import os
import tensorflow as tf
from tensorflow.keras import layers, models
from tensorflow.keras.applications import EfficientNetB0
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.callbacks import EarlyStopping, ReduceLROnPlateau
from sklearn.model_selection import train_test_split
from sklearn.utils.class_weight import compute_class_weight
import numpy as np

# Enable mixed precision training for faster performance on GPUs
from tensorflow.keras.mixed_precision import set_global_policy
set_global_policy('mixed_float16')

# Set the dataset path
data_path = r'C:\Users\imady\Desktop\ai\aiarab\archive\brain_tumor_dataset'

# Function to load data from folders
def load_data(data_path, target_size=(128, 128)):
    images = []
    labels = []
    
    # Define paths for 'yes' and 'no' folders
    yes_path = os.path.join(data_path, 'yes')
    no_path = os.path.join(data_path, 'no')
    
    # Load images from 'yes' folder (label 1)
    for img_name in os.listdir(yes_path):
        img_path = os.path.join(yes_path, img_name)
        if os.path.isfile(img_path):
            img = tf.keras.preprocessing.image.load_img(img_path, target_size=target_size)
            img = tf.keras.preprocessing.image.img_to_array(img)
            img = tf.keras.applications.efficientnet.preprocess_input(img)
            images.append(img)
            labels.append([1, 0])  # Label for 'yes' (tumor)
    
    # Load images from 'no' folder (label 0)
    for img_name in os.listdir(no_path):
        img_path = os.path.join(no_path, img_name)
        if os.path.isfile(img_path):
            img = tf.keras.preprocessing.image.load_img(img_path, target_size=target_size)
            img = tf.keras.preprocessing.image.img_to_array(img)
            img = tf.keras.applications.efficientnet.preprocess_input(img)
            images.append(img)
            labels.append([0, 1])  # Label for 'no' (no tumor)
    
    return np.array(images), np.array(labels)

# Load dataset
X, y = load_data(data_path, target_size=(128, 128))
print(f'Dataset loaded: {X.shape[0]} images')

# Split dataset (80% train, 10% validation, 10% test)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
X_val, X_test, y_val, y_test = train_test_split(X_test, y_test, test_size=0.5, random_state=42)

# Create TensorFlow datasets for efficient data loading
def create_dataset(X, y, batch_size=16, shuffle=True):
    dataset = tf.data.Dataset.from_tensor_slices((X, y))
    if shuffle:
        dataset = dataset.shuffle(buffer_size=len(X))
    dataset = dataset.batch(batch_size)
    dataset = dataset.cache()  # Cache data in memory
    dataset = dataset.prefetch(tf.data.experimental.AUTOTUNE)  # Prefetch data
    return dataset

train_dataset = create_dataset(X_train, y_train, batch_size=4)
val_dataset = create_dataset(X_val, y_val, batch_size=16, shuffle=False)
test_dataset = create_dataset(X_test, y_test, batch_size=16, shuffle=False)

# Class Weighting (to handle imbalanced data)
class_weights = compute_class_weight(
    'balanced', 
    classes=np.unique(np.argmax(y, axis=1)), 
    y=np.argmax(y, axis=1)
)
class_weights = dict(enumerate(class_weights))

# Create base model (EfficientNetB0)
base_model = EfficientNetB0(
    include_top=False,
    weights='imagenet',
    input_shape=(128, 128, 3)
)

# Freeze base model layers for initial training
base_model.trainable = True

# Build transfer learning model
model = models.Sequential([
    layers.Input(shape=(128, 128, 3)),
    base_model,
    layers.GlobalAveragePooling2D(),
    layers.Dense(128, activation='sigmoid'),  # Simplified head
    layers.Dropout(0.3),
    layers.BatchNormalization(),
    layers.Dense(2, activation='softmax')  # Binary classification (2 classes)
])

# Compile model
initial_learning_rate = 0.001
model.compile(
    optimizer=Adam(learning_rate=initial_learning_rate),
    loss='categorical_crossentropy',  # Use categorical crossentropy for binary classification
    metrics=[
        tf.keras.metrics.BinaryAccuracy(name='accuracy'),
        tf.keras.metrics.Precision(name='precision'),
        tf.keras.metrics.Recall(name='recall'),
        tf.keras.metrics.AUC(name='auc')
    ]
)

# Callbacks
early_stop = EarlyStopping(
    monitor='val_loss',
    patience=10,
    restore_best_weights=True
)

reduce_lr = ReduceLROnPlateau(
    monitor='val_loss',
    factor=0.2,
    patience=3,
    min_lr=1e-7
)

# Train the model
print("\nTraining model...")
history = model.fit(
    train_dataset,
    validation_data=val_dataset,
    epochs=3,  # Train for 30 epochs
    class_weight=class_weights,
    callbacks=[early_stop, reduce_lr],
    verbose=1
)

# Fine-tuning (unfreeze base model)
print("\nFine-tuning model...")
base_model.trainable = True
model.compile(
    optimizer=Adam(learning_rate=1e-6),  # Smaller learning rate for fine-tuning
    loss='categorical_crossentropy',
    metrics=[
        tf.keras.metrics.BinaryAccuracy(name='accuracy'),
        tf.keras.metrics.Precision(name='precision'),
        tf.keras.metrics.Recall(name='recall'),
        tf.keras.metrics.AUC(name='auc')
    ]
)

history_fine = model.fit(
    train_dataset,
    validation_data=val_dataset,
    epochs=1,  # Fine-tune for 10 epochs
    class_weight=class_weights,
    callbacks=[early_stop],
    verbose=1
)

# Evaluate final performance
print("\nModel evaluation:")
test_results = model.evaluate(test_dataset, verbose=0)
test_loss = test_results[0]
test_acc = test_results[1]
test_precision = test_results[2]
test_recall = test_results[3]
test_auc = test_results[4]

print(f"Final Test Loss: {test_loss:.4f}")
print(f"Accuracy: {test_acc*100:.2f}%")
print(f"Precision: {test_precision*100:.2f}%")
print(f"Recall: {test_recall*100:.2f}%")
print(f"AUC: {test_auc*100:.2f}%")

# Save model
model.save('brain_tumer.keras')