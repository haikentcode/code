import cv2
 
cap=cv2.VideoCapture(0)
i=0


while(True):
           ret,frame=cap.read()
           cv2.imshow('frame',frame)
           cv2.imwrite(str(i)+".jpg",frame)
           i+=1
           if cv2.waitKey(2000)& 0xFF==ord('q'):
                 break
cv2.destroyAllWindows()
        
