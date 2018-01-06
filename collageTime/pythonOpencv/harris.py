import cv2
import numpy as np

filename='data/harri.png'
img=cv2.imread(filename)
gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

#find Harris corners
res=np.float32(gray)
dst=cv2.cornerHarris(gray,2,3,0.04)
dst=cv2.dilate(dst,None)

#Threshold for an optimal vlue it may vary depending on the image
img[dst>0.01*dst.max()]=[0,0,255]

cv2.imshow('dst',img)
if cv2.waitKey(0) & 0xFF == 27:
  cv2.destroyAllWindow()



