import gradio as gr
import tensorflow as tf
import numpy as np
import os
from tensorflow.keras.preprocessing import image
from tensorflow.keras.applications.efficientnet import preprocess_input

# ======================
# MODEL LOADING
# ======================
MODEL_NAME = 'brain_tumer.keras'
model = None
load_error = ""

# Get absolute path and verify
model_path = os.path.abspath(MODEL_NAME)
print(f"🔍 Model path: {model_path}")

if os.path.exists(model_path):
    try:
        # Load Keras format model directly
        print("⏳ Attempting to load .keras model...")
        model = tf.keras.models.load_model(model_path)
        print(f"✅ Model loaded successfully! TF {tf.__version__}")
        print(model.summary())  # Verify model architecture
        
    except Exception as e:
        load_error = str(e)
        print(f"❌ Load error: {load_error}")
else:
    load_error = f"Model file not found at: {model_path}"

# ======================
# PREDICTION FUNCTION
# ======================
def predict_tumor(img):
    if not model:
        return (
            "Error: Model failed to load",
            {"Error": load_error},
            False, False, True
        )
    
    try:
        if img is None:
            return (
                "Error: No image uploaded",
                {},
                False, True, False
            )
        
        # Preprocess image
        img = image.img_to_array(img)
        img = tf.image.resize(img, [128, 128])  # Resize to expected input
        img = preprocess_input(img)
        img = np.expand_dims(img, axis=0)
        
        # Predict
        prediction = model.predict(img)
        tumor_prob = round(prediction[0][0] * 100, 2)
        no_tumor_prob = round(prediction[0][1] * 100, 2)  # Assuming index 1 is tumor

        # Calculate confidence metrics
        confidence = max(tumor_prob, no_tumor_prob)
        accuracy = 95.7  # Replace with your model's actual test accuracy
        
        diagnosis = "Tumor Detected 🚨" if tumor_prob > 50 else "No Tumor Detected ✅"

        return (
            diagnosis,
            {
                "Tumor Probability (%)": tumor_prob,
                "Healthy Probability (%)": no_tumor_prob,
                "Confidence Level (%)": confidence,
                "Model Accuracy (%)": accuracy
            },
            True, False, False
        )
  
    
    except Exception as e:
        return (
            f"Analysis Error: {str(e)}",
            {"Error": "Processing failed"},
            False, False, True
        )

# ======================
# GRADIO INTERFACE
# ======================
with gr.Blocks(title="Brain Tumor Detection", theme=gr.themes.Soft()) as demo:
    gr.Markdown("# 🧠 Brain Tumor Detection MRI Scanner")
    
    with gr.Row():
        with gr.Column():
            gr.Markdown("## Upload Scan")
            scan_input = gr.Image(label="MRI Scan", type="pil")
            status_checkboxes = gr.CheckboxGroup(
                ["X", "Diagnosis", "Error"],
                label="Status",
                interactive=False
            )
        
        with gr.Column():
            gr.Markdown("## Analyze")
            analyze_btn = gr.Button("Run Analysis", variant="primary")
            error_checkbox = gr.Checkbox(label="Error", value=bool(load_error))
    
    with gr.Row():
        diagnosis_output = gr.Label(label="Diagnosis", value="Awaiting input...")
        probability_output = gr.JSON(label="Probabilities")
    
    gr.Markdown(f"""
    **System Status**  
    Model: {"✅ Loaded" if model else "❌ Failed"}  
    Error: {load_error if load_error else "None"}  
    TensorFlow: {tf.__version__}
    """)

    scan_input.change(
        fn=lambda img: (["X"] if img else [], False),
        inputs=scan_input,
        outputs=[status_checkboxes, error_checkbox]
    )
    
    analyze_btn.click(
        fn=predict_tumor,
        inputs=scan_input,
        outputs=[
            diagnosis_output,
            probability_output,
            status_checkboxes,
            status_checkboxes,
            error_checkbox
        ]
    )
if __name__ == "__main__":
    demo.launch(share=True)

