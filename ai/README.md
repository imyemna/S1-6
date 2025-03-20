# Brain Tumor Detection MRI Scanner

A web application for detecting brain tumors in MRI scans using TensorFlow and Flask.

## Features

- Modern, responsive web interface
- Drag-and-drop image upload
- Real-time image preview
- System status monitoring
- Detailed probability analysis
- Loading indicators and error handling

## Prerequisites

- Python 3.8 or higher
- TensorFlow 2.15.0 or higher
- Flask 3.0.0 or higher
- Your trained `.keras` model file named `brain_tumer.keras`

## Setup

1. Clone this repository
2. Install the required dependencies:
   ```bash
   pip install -r requirements.txt
   ```
3. Place your trained model file (`brain_tumer.keras`) in the root directory

## Running the Application

1. Start the Flask server:
   ```bash
   python app.py
   ```
2. Open your web browser and navigate to:
   ```
   http://localhost:5000
   ```

## Testing the Model

You can test if your model is compatible and working properly using the included test script:

```bash
python test_model.py [optional_test_image_path]
```

This will:
1. Check if the model file exists
2. Try to load the model
3. Verify model architecture and input/output shapes
4. Test prediction on a sample image (either provided or a generated black square)

## Usage

1. Upload an MRI scan image by either:
   - Clicking the upload area and selecting a file
   - Dragging and dropping an image file
2. Click "Run Analysis" to process the image
3. View the results including:
   - Diagnosis
   - Tumor probability
   - Healthy probability
   - System status

## Troubleshooting

### "Processing failed" or "Analysis Error"

This general error can be caused by several issues:

1. **Model not found**: Ensure your model file is in the root directory and named `brain_tumer.keras`
2. **Model compatibility**: Your model should:
   - Accept inputs of shape (batch, height, width, 3) - typically (None, 128, 128, 3)
   - Output a shape with at least 2 classes (one for tumor, one for no tumor)
   - Be a binary classification model
3. **Image format issues**: 
   - Try different image formats (PNG, JPG)
   - Ensure the image is a proper MRI scan format
   - Check for corruption or unusual color spaces

### Model Loading Failures

If the model fails to load, check:
1. TensorFlow version compatibility with your model
2. Model file integrity
3. Memory constraints (if the model is very large)

### Debug Logs

The application generates detailed logs that can help diagnose issues:
1. Check the terminal where you run `python app.py`
2. Look for INFO, WARNING and ERROR level messages
3. Try running the test script to isolate model-specific issues

## File Structure

```
.
├── app.py              # Flask backend server
├── test_model.py       # Model testing script
├── brain_tumer.keras   # Your trained model file
├── requirements.txt    # Python dependencies
├── README.md           # This file
└── static/
    └── index.html      # Frontend web interface
```

## Notes

- The application expects MRI scan images in common formats (PNG, JPG, JPEG)
- Maximum file size is limited to 10MB
- The model should be trained for binary classification (tumor/no tumor)
- The application automatically resizes images to match your model's expected input size 