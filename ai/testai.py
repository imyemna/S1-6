import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

data = pd.read_csv('cancer.csv')

x= data.drop(columns=["diagnosis(1=m, 0=b)"])

y= data["diagnosis(1=m, 0=b)"]

x_test,x_train,y_test,y_train= train_test_split(x,y,test_size=0.5)

model = tf.keras.models.Sequential()

model.add(tf.keras.layers.Dense(64, input_shape=(x_train.shape[1],), activation='sigmoid'))

model.add(tf.keras.layers.Dense(64,activation='sigmoid'))

model.add(tf.keras.layers.Dense(1,activation='sigmoid'))

model.compile(optimizer='adam', loss='binary_crossentropy',metrics=['accuracy'])

model.fit(x_train, y_train, epochs=1000, batch_size=10, validation_data=(x_test, y_test))

loss, accuracy = model.evaluate(x_test, y_test)

print(f'Test Accuracy: {accuracy * 100:.2f}%')