import cv2
import numpy as np
from matplotlib import pyplot as plt
cap=cv2.VideoCapture(0)

#while 1:
	_,img = cap.read()
	color = ('b','g','r')
	for i,col in enumerate(color):
	    histr = cv2.calcHist([img],[i],None,[256],[0,256])
	    plt.plot(histr,color = col)
	    plt.xlim([0,256])
	plt.show()
	if cv2.waitKey(1)& 0xFF==ord('q'):
		  break
cap.release()
cv2.destroyAllWindows()