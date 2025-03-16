import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from tkinter import *
from tkinter import ttk
import gradio as gr


data = pd.read_csv('cancer.csv')

x= data.drop(columns=["diagnosis(1=m, 0=b)"])

y= data["diagnosis(1=m, 0=b)"]

x_test,x_train,y_test,y_train= train_test_split(x,y,test_size=0.5)

model = tf.keras.models.Sequential()

model.add(tf.keras.layers.Dense(256, input_shape=(x_train.shape[1],), activation='sigmoid'))

model.add(tf.keras.layers.Dense(256,activation='sigmoid'))

model.add(tf.keras.layers.Dense(1,activation='sigmoid'))

model.compile(optimizer='adam', loss='binary_crossentropy',metrics=['accuracy'])

model.fit(x_train, y_train, epochs=10, batch_size=10, validation_data=(x_test, y_test))

loss, accuracy = model.evaluate(x_test, y_test)

print(f'Test Accuracy: {accuracy * 100:.2f}%')


def predict_gui():
    root = Tk()
    root.title("Cancer Diagnosis Predictor")

    entries = {}
    for idx, feature in enumerate(x.columns):
        Label(root, text=feature).grid(row=idx, column=0)
        entries[feature] = Entry(root)
        entries[feature].grid(row=idx, column=1)

    def make_prediction():
        input_data = [float(entries[feature].get()) for feature in x.columns]
        prediction = model.predict(np.array([input_data]), verbose=0)[0][0]
        result = "Malignant" if prediction > 0.5 else "Benign"
        result_label.config(text=f"Diagnosis: {result} (Confidence: {prediction:.4f})")

    Button(root, text="Predict", command=make_prediction).grid(row=len(x.columns)+1, columnspan=2)
    result_label = Label(root, text="")
    result_label.grid(row=len(x.columns)+2, columnspan=2)

    root.mainloop()

# Call this after training
predict_gui()




def gradio_predict(*args):
    input_data = np.array([args], dtype=float)
    prediction = model.predict(input_data, verbose=0)[0][0]
    return "Malignant 🚨" if prediction > 0.5 else "Benign ✅"

inputs = [gr.Number(label=feature) for feature in x.columns]
interface = gr.Interface(
    fn=gradio_predict,
    inputs=inputs,
    outputs="label",
    title="Cancer Diagnosis Predictor",
    description="Enter patient measurements to get diagnosis prediction"
)

# Call this after training
interface.launch()


print("\n** Enter patient data for prediction **")
while True:
    try:
        new_input = []
        for feature in x.columns:
            value = float(input(f"Enter {feature}: "))
            new_input.append(value)
        
        new_data = np.array([new_input])
        prediction = model.predict(new_data, verbose=0)
        diagnosis = "Malignant (1)" if prediction[0][0] > 0.5 else "Benign (0)"
        print(f"Prediction: {diagnosis} | Confidence: {prediction[0][0]:.4f}\n")
        
        continue_pred = input("Predict another? (y/n): ").lower()
        if continue_pred != 'y':
            break
    except ValueError:
        print("Invalid input. Please enter numeric values only.\n")

