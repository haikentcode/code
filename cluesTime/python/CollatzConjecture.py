import time
import sys
import math
from functools import wraps
import os

sys.setrecursionlimit(150000)
cache = {}

def memoize(func):
    global cache
    @wraps(func)
    def wrapper(*args):
        if args not in cache:
            cache[args] = func(*args)
        return cache[args]
    return wrapper

@memoize
def ccstep(n):
    if n == 1:
        return 1

    if not (n & (n - 1)):
        return int(math.log(n&-n,2)+1)

    if n %2 == 0:
        return 1+ccstep(n/2)
    else:
        return 1+ccstep(3*n+1)

if __name__ == "__main__":
    _max = 0
    count = 1
    while count < 100000 :
        # os.system('clear')
        # print [ x[0] for x in cache.keys()]
        _max = max(_max,ccstep(count))
        count+=1
    print(_max)



if __name__ == "__main__#":
    import tensorflow as tf
    import tensorflow.contrib.eager as tfe
    tfe.enable_eager_execution()
    a = tf.constant(input("Your lucky number:"))

    counter = 0

    t1 = time.time()
    while not tf.equal(a, 1):
      counter+=1
      if tf.equal(a % 2, 0):
        a = a / 2
      else:
        a = 3 * a + 1
      print(a)

    print("step %d in time=%f" %(counter,time.time()-t1))
