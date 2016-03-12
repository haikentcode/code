import threading
import time
exitFlag=0
threadLock=threading.Lock()
class hk(threading.Thread):
      def __init__(self,name):
           threading.Thread.__init__(self)
           self.name=name
      def run(self):
           a=100
           while a:
               threadLock.acquire()
               print self.name,
               a-=1
               threadLock.release()



t1=hk("aditi")
t2=hk("hitesh")
t1.start()
t2.start()
threads=[]
threads.append(t1)
threads.append(t2)
for t in threads:
      t.join()

print "we love each other always :) "
print "you are happy now"
