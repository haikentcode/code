import os
import collections
import sys
import re
import thread
import time
from pymongo import MongoClient

client=MongoClient()
filelist=[]
db=client.haios
filelistdb=db.filelist
def scan_dir(dir):
	global filelist
	for name in os.listdir(dir):
	  try: 
		path = os.path.join(dir, name)
		if os.path.isfile(path):
			 filelist.append(path)
			 filelistdb.insert_one({"filepath":path,"filename":name})
		else:
			thread.start_new_thread(scan_dir,(path,))
	  except:
		   er="error"


username="hitesh"
Pictures="/home/" #+username+"/Pictures/"
path1="/home/hitesh/Pictures/haikent/personal"
scan_dir(path1)
while 1:
	print len(filelist)
	time.sleep(1)

