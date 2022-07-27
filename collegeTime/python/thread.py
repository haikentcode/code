import thread
import time

def msg(tname,delay):
  count=0
  while count<5:
     time.sleep(delay)
     count +=1
     print "%s:%s" % (tname,time.ctime(time.time()))


try:
  thread.start_new_thread(msg,("haikent",2))
  thread.start_new_thread(msg,("aditi",4))
except:
  print "Error"

while 1:
  pass
