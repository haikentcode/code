import cv2
import numpy as np
import sys
from matplotlib import pyplot as plt

img=sys.argv[0]
img=cv2.imread(img,0)
plt.hist(img.ravel(),255,[0,256]);plt.show()


