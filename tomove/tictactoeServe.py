from flask import Flask
import pickle
import numpy as np
app = Flask(__name__)


@app.route('/<game>')
def predict(game):
   model = pickle.loads(open("t3brain.bin",'rb').read())
   gi = [list(x) for x in game.split(",")]
   data = np.array(gi)
   data[data == "x"] = 1
   data[data == "o"] = 2
   data[data == "b"] = 0
   data = data.astype(np.int)
   print(data)
   print(model.predict(data))
   return "Hello World"

if __name__ == '__main__':
   app.run()
