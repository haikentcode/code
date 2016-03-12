import threading
import time
import random

class haikuthread (threading.Thread):
        BIGSUM=0
	def __init__(self,l,sp,lp):
		threading.Thread.__init__(self)
		self.mlist=l
		self.startp=sp
		self.endp=lp
	def run(self):
	    self.BIGSUM +=sum(self.mlist[x] for x in range(self.startp,self.endp+1))



s=0;
for a in range(100000):
  h=haikuthread([3,5,7,8,11,4,76,12,76,32],random.randrange(10),random.randrange(10))
  h.start()
  s=h.BIGSUM

print s
