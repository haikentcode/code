import argparse
import cv2

ap=argparse.ArgumentParser()
ap.add_argument("-i","--image",required=True,help="Path to image")

args=vars(ap.parse_args())

image=cv2.imread(args["image"])

print "Width: %d px" % (image.shape[1])
print "height: %d px" % (image.shape[0])
print "channels: %d " % (image.shape[2])

(b,g,r)=image[0,0]

print "Pixel at (0,0) b:%d ,g:%d ,r:%d" % (b,g,r)
def hk(t):
    for i in range(len(t)):
             t[i]=254-t[i]
for i in range(image.shape[0]):
   for j in range(image.shape[1]):
             t=image[i,j]
             hk(t)
             image[i,j]=t

cv2.imshow("Image",image)
cv2.waitKey(0)
