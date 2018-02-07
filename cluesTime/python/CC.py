import time
counter=0
a = input("Your lucky number:")
t1=time.time()
while not  a==1 :
  counter+=1
  if a % 2== 0:
    a = a / 2
  else:
    a = 3 * a + 1
  print(a)

print "step %d in time=%f" % (counter,time.time()-t1)
