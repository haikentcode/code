import cv2
import numpy as np
cap=cv2.VideoCapture(0)
while 1:
	 _,frame=cap.read()
	 frame=cv2.flip(frame,1)
	 hsv=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
	 lower_blue=np.array([110,55,55])
	 upper_blue=np.array([130,255,255])
	 mask = cv2.inRange(hsv, lower_blue, upper_blue)
	 res=cv2.bitwise_and(frame,frame,mask=mask)
	 print res
	 cv2.imshow('frame2',res)
	 k= cv2.waitKey(30) & 0xff
	 if k == 27:
            break