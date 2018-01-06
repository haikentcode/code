import numpy as np
import cv2
from objects import objects 
cap=cv2.VideoCapture("http://10.42.0.41:8080/video")
while(True):
    ret,frame=cap.read()
    gray=frame#cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    
    cv2.imshow('frame',gray)
    if cv2.waitKey(1)& 0xFF==ord('q'):
        break

cap.release()
cv2.destroyAllWindows()

