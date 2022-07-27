import numpy as np
import cv2
from descriptor import descriptor as des
from distance import distance as dis
import os
import sys



class Face:
    'Extracting Face From Image'
    def __init__(self,scaleFactor=1.2,minNeighbors=5,minh=80,minw=80):
        self.scaleFactor=scaleFactor
        self.minNeighbors=minNeighbors
        self.minh=minh
        self.minw=minw

    def getFaces(self,image): #return face images list from image
        gimage=cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
        faceObj=cv2.CascadeClassifier('../xmldata/haarcascade_frontalface_default.xml')
        return self.getData(gimage,faceObj)

    def getData(self,image,cascadeObj):
        faces = cascadeObj.detectMultiScale(image,self.scaleFactor,self.minNeighbors,minSize=(self.minh,self.minw)) #check
        faceImages=[]
        for (x,y,w,h) in faces:
            #crop image -> cropImage=image[y:y+w,x:x+h]
            cropImage=image[y:y+w,x:x+h]
            faceImages.append(cropImage)
        return faceImages    #  NOTE: return oringinal face not gray



i=0
cap=cv2.VideoCapture(0)
def getFaces(idc,img):#imagePath
           global i
           face=Face(1.9,3,20,20)
           faces=face.getFaces(img)
           print("find faces=",len(faces))
           for image in faces:
               cv2.imwrite(str(idc)+"."+str(i)+".jpg",image)
               i+=1

if __name__ == "__main__":
        idc=eval(input("candidateID(int):"))
        while(True):
           ret,frame=cap.read()
           print(frame)
           if not ret : continue
           gray=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
           cv2.imshow('frame',frame)
           getFaces(idc,frame)
           if cv2.waitKey(2000)& 0xFF==ord('q'):
                 break
                 
        cv2.destroyAllWindows()
           
