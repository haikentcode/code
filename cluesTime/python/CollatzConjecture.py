import tensorflow as tf
import tensorflow.contrib.eager as tfe
import time
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

print "step %d in time=%f" %(counter,time.time()-t1)


