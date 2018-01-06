import numpy as np
import argparse
import cv2
import argparse
ap = argparse.ArgumentParser()
ap.add_argument("-i","--image",required=True,help="Path to the image")
args=vars(ap.parse_args())


image = cv2.imread(args["image"])
gray=cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
blurred=cv2.GaussianBlur(gray,(11,11),0)
cv2.imshow("Image",image)
edged=cv2.Canny(blurred,30,150)
dd=cv2.resize(edged,(600,600),interpolation=cv2.INTER_AREA)
cv2.imshow("Edges",dd)
(cnts,_)=cv2.findContours(edged.copy(),cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)

print "I count %d coints in this image" % (len(cnts))

coins=image.copy()
cv2.drawContours(coins,cnts,-1,(0,255,0),2)
c=cv2.resize(coins,(600,600),interpolation=cv2.INTER_AREA)
cv2.imshow("Coins",c)
cv2.waitKey(0)


for (i,c) in enumerate(cnts):
     (x,y,w,h)=cv2.boundingRect(c)
     print "Coin #%d" % (i+1)
     coin = image[y:y+h,x:x+w]
     cv2.imshow("Coin",coin)
     mask=np.zeros(image.shape[:2],dtype="unit8")
     ((centerX,centerY),radius) = cv2.minEnclosingCircle(c)
     cv2.circle(mask,(int(centerX),int(centerY)),int(radius),255,-1)
     mask=mask[y:y+h,x:x+w]
