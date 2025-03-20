from flask import Flask, request, jsonify, send_from_directory
import tensorflow as tf
import numpy as np
import os
import traceback
import logging
from tensorflow.keras.preprocessing import image
from tensorflow.keras.applications.efficientnet import preprocess_input
from PIL import Image
import io

# Configure logging
logging.basicConfig(level=logging.INFO, 
                    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
                    handlers=[logging.StreamHandler()])
logger = logging.getLogger(__name__)

app = Flask(__name__, static_folder='static')

# ======================
# MODEL LOADING
# ======================
MODEL_NAME = 'brain_tumer.keras'
model = None
load_error = ""
model_input_shape = None

# Function to check if the model is compatible with our preprocessing pipeline
def check_model_compatibility():
    global model_input_shape
    
    if not model:
        return False, "Model not loaded"
    
    try:
        # Get the input shape from the model
        input_layer = model.layers[0]
        model_input_shape = input_layer.input_shape
        
        logger.info(f"Model input shape: {model_input_shape}")
        
        # Basic validation
        if len(model_input_shape) != 4:  # Batch, height, width, channels
            return False, f"Expected 4D input shape, got {len(model_input_shape)}D"
        
        # Check output shape
        output_layer = model.layers[-1]
        output_shape = output_layer.output_shape
        
        logger.info(f"Model output shape: {output_shape}")
        
        if len(output_shape) != 2 or output_shape[1] < 2:
            return False, f"Expected output shape with at least 2 classes, got {output_shape}"
            
        return True, None
        
    except Exception as e:
        logger.error(f"Error checking model compatibility: {str(e)}")
        return False, str(e)

# Get absolute path and verify
model_path = os.path.abspath(MODEL_NAME)
logger.info(f"🔍 Model path: {model_path}")

if os.path.exists(model_path):
    try:
        logger.info("⏳ Attempting to load .keras model...")
        model = tf.keras.models.load_model(model_path)
        logger.info(f"✅ Model loaded successfully! TF {tf.__version__}")
        model.summary()
        
        # Check model compatibility
        compatible, error_msg = check_model_compatibility()
        if not compatible:
            logger.warning(f"Model compatibility check failed: {error_msg}")
            load_error = f"Model compatibility issue: {error_msg}"
    except Exception as e:
        load_error = str(e)
        logger.error(f"❌ Load error: {load_error}")
        logger.error(traceback.format_exc())
else:
    load_error = f"Model file not found at: {model_path}"
    logger.error(load_error)

def predict_tumor(img_data):
    if not model:
        logger.error("Model not loaded, cannot predict")
        return {
            "error": "Model failed to load",
            "details": load_error
        }
    
    try:
        # Convert bytes to PIL Image
        logger.info("Opening image from bytes")
        img = Image.open(io.BytesIO(img_data))
        logger.info(f"Image opened successfully: format={img.format}, size={img.size}, mode={img.mode}")
        
        # Convert RGBA to RGB if needed
        if img.mode == 'RGBA':
            logger.info("Converting RGBA to RGB")
            background = Image.new("RGB", img.size, (255, 255, 255))
            background.paste(img, mask=img.split()[3])
            img = background
        
        # Preprocess image
        logger.info("Converting to array")
        img = image.img_to_array(img)
        logger.info(f"Array shape before resize: {img.shape}")
        
        # Use model input shape if available
        target_size = [128, 128]
        if model_input_shape and len(model_input_shape) >= 3:
            height, width = model_input_shape[1], model_input_shape[2]
            if height is not None and width is not None:
                target_size = [height, width]
                logger.info(f"Using model's target size: {target_size}")
        
        logger.info(f"Resizing image to {target_size}")
        img = tf.image.resize(img, target_size)
        logger.info(f"Array shape after resize: {img.shape}")
        
        logger.info("Applying preprocessing")
        img = preprocess_input(img)
        
        logger.info("Expanding dimensions")
        img = np.expand_dims(img, axis=0)
        logger.info(f"Final input shape: {img.shape}")
        
        # Predict
        logger.info("Running prediction")
        prediction = model.predict(img, verbose=0)
        logger.info(f"Raw prediction result: {prediction}")
        
        # Check shape of prediction to validate model output
        if len(prediction.shape) != 2 or prediction.shape[1] < 2:
            logger.error(f"Model output shape is unexpected: {prediction.shape}")
            return {
                "error": "Model output format is incorrect",
                "details": f"Expected at least 2 classes, got {prediction.shape[1] if len(prediction.shape) > 1 else 'scalar'}"
            }
        
        try:
            tumor_prob = round(float(prediction[0][0]) * 100, 2)
            no_tumor_prob = round(float(prediction[0][1]) * 100, 2)
        except IndexError as e:
            logger.error(f"Index error accessing prediction: {str(e)}")
            return {
                "error": "Model output format is incompatible",
                "details": f"Could not extract class probabilities from output: {str(e)}"
            }
        
        logger.info(f"Tumor probability: {tumor_prob}%, No tumor probability: {no_tumor_prob}%")
        
        confidence = max(tumor_prob, no_tumor_prob)
        accuracy = 95.7
        
        diagnosis = "Tumor Detected 🚨" if tumor_prob > 50 else "No Tumor Detected ✅"
        
        return {
            "diagnosis": diagnosis,
            "probabilities": {
                "tumor": tumor_prob,
                "healthy": no_tumor_prob,
                "confidence": confidence,
                "accuracy": accuracy
            }
        }
    
    except ValueError as e:
        logger.error(f"Value error during processing: {str(e)}")
        logger.error(traceback.format_exc())
        return {
            "error": "Image Processing Error",
            "details": f"Invalid image data: {str(e)}"
        }
    except IOError as e:
        logger.error(f"IO error during processing: {str(e)}")
        logger.error(traceback.format_exc())
        return {
            "error": "Image Format Error",
            "details": f"Cannot read image file: {str(e)}"
        }
    except Exception as e:
        logger.error(f"Unexpected error during processing: {str(e)}")
        logger.error(traceback.format_exc())
        return {
            "error": "Analysis Error",
            "details": str(e)
        }

@app.route('/')
def serve_index():
    return send_from_directory('static', 'index.html')

@app.route('/predict', methods=['POST'])
def predict():
    logger.info("Received prediction request")
    
    if 'image' not in request.files:
        logger.warning("No image file in request")
        return jsonify({"error": "No image file provided"}), 400
    
    file = request.files['image']
    if file.filename == '':
        logger.warning("Empty filename in request")
        return jsonify({"error": "No selected file"}), 400
    
    logger.info(f"Processing file: {file.filename}, content type: {file.content_type}")
    
    try:
        img_data = file.read()
        logger.info(f"Read {len(img_data)} bytes of image data")
        
        result = predict_tumor(img_data)
        logger.info(f"Prediction completed: {result}")
        
        if "error" in result:
            return jsonify(result), 400
            
        return jsonify(result)
    except Exception as e:
        error_details = str(e)
        logger.error(f"Unhandled exception in predict endpoint: {error_details}")
        logger.error(traceback.format_exc())
        return jsonify({
            "error": "Processing failed", 
            "details": error_details
        }), 500

@app.route('/model-status')
def model_status():
    return jsonify({
        "model_loaded": model is not None,
        "error": load_error if load_error else None,
        "tensorflow_version": tf.__version__
    })

if __name__ == '__main__':
    app.run(debug=True) 