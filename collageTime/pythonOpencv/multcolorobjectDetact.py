import numpy as np
import cv2

cap=cv2.VideoCapture(0)
while(True):
    ret,frame=cap.read()
    frame=cv2.flip(frame,1)

    #BGR TO SHV
    hsv=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)

    greenL,greenU=np.array([110,50,50]),np.array([130,225,225])
    redL,redU=np.array([0,50,50]),np.array([30,225,225])
    blueL,blueU=np.array([65,129,55]),np.array([80,255,255])
    maskg=cv2.inRange(hsv,greenL,greenU)
    maskr=cv2.inRange(hsv,redL,redU)
    maskb=cv2.inRange(hsv,blueL,blueU)

    resg=cv2.bitwise_and(frame,frame,mask=maskg)
    resr=cv2.bitwise_and(frame,frame,mask=maskr)
    resb=cv2.bitwise_and(frame,frame,mask=maskb)

    cv2.imshow('framer',resr)
    cv2.imshow('frameb',resb)
    cv2.imshow('frameg',resg)
    if cv2.waitKey(1)& 0xFF==ord('q'):
        break

cap.release()
cv2.destroyAllWindows()

