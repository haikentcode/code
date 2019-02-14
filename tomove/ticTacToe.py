import numpy as np
import pandas as pd

from sklearn.preprocessing import LabelEncoder, OneHotEncoder
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score

from keras.models import Sequential
from keras.layers import Dense

class TicTacToeModel:
    def __init__(self,dataset):
        self.dataSet = dataset

    def prepareDataset(self):
        # Import dataset
        dataset = pd.read_csv(self.dataSet)
        self.X = dataset.iloc[:, 0:9].values
        self.y = dataset.iloc[:, 9:10].values

        # Encode categorical variables as numeric
        # labelencoder_X = LabelEncoder()
        # for _ in range(9):
        #     self.X[:, _] = labelencoder_X.fit_transform(self.X[:, _])

        self.X [self.X  == "x"] = 1
        self.X [self.X  == "o"] = 2
        self.X [self.X  == "b"] = 0


        # Onehot encode all dependent categorical variablesp

        # print(self.X[0])
        # onehotencoder = OneHotEncoder(categorical_features = [0,1,2,3,4,5,6,7,8])
        # self.X = onehotencoder.fit_transform(self.X).toarray()
        # print(self.X[0])
        #
        # # Remove every third column to avoid dummy variable trap
        # # Only need 2 bits to represent 3 possibilities
        # self.X = np.delete(self.X, [0,3,6,9,12,15,18,21,24], axis=1)

        # Encode target categorical variable
        labelencoder_y = LabelEncoder()
        self.y[:, 0] = labelencoder_y.fit_transform(self.y[:, 0])

        # Train/test split
        self.X_train, self.X_test, self.y_train, self.y_test = train_test_split(self.X, self.y, test_size=0.2, random_state=42)
        print(self.X_train[0])


    def trainModel(self):
        # Initialize neural network
        nnet = Sequential()

        # Add first hidden layer (and input layer)
        nnet.add(Dense(units=9, kernel_initializer='uniform', activation='relu', input_dim=9))

        # Add second hidden layer
        nnet.add(Dense(units=9, kernel_initializer='uniform', activation='relu'))

        # Add output layer
        nnet.add(Dense(units=1, kernel_initializer='uniform', activation='sigmoid'))

        # Compile network
        nnet.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

        # Train network
        nnet.fit(self.X_train, self.y_train, batch_size=10, epochs=100)
        self.model = nnet

    def validate(self):
        # Predicting the test set results
        y_pred = self.model.predict(self.X_test)
        print(y_pred)

    def saveModel(self):
        import pickle
        _model = pickle.dumps(self.model)
        with open("t3brain.bin",'wb') as f:
            f.write(_model)



if __name__ == "__main__":
    # tm = TicTacToeModel("./tic-tac-toe.data")
    # tm.prepareDataset()
    # tm.trainModel()
    # tm.saveModel()

    import pickle
    model = pickle.loads(open("t3brain.bin",'rb').read())

    labelencoder_X = LabelEncoder()
    onehotencoder = OneHotEncoder(categorical_features = [0,1,2,3,4,5,6,7,8])
    data = np.array([["x","o","x","o","o","x","x","x",'o'],
     ["x","o","x","o","x","x","o","x",'b'],
     ["b","o","o","o","x","x","x","x",'o'],
     ["o","x","x","x","x","o","o","o",'x'],
     ["o","x","x","x","b","o","x","o",'x'],
     ["o","x","x","x","o","o","o","x",'x'],
     ["o","x","o","x","x","o","x","o",'x'],
     ["o","x","o","x","o","x","x","o",'x'],
     ["o","b","o","o","x","x","x","o",'x'],
     ["x","b","x","b","b","o","b","x",'b']])

    data[data == "x"] = 1
    data[data == "o"] = 2
    data[data == "b"] = 0

    data = data.astype(np.int)
    print(model.predict(data))

    # while True:
    #     data = np.array([list(input("game->"))])
    #     data[data == "x"] = 1
    #     data[data == "o"] = 2
    #     data[data == "b"] = 0
    #     print(tm.model.predict(data))
