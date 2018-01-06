#!/usr/bin/env python
import sys
imageName=sys.argv[1]
password=sys.argv[2]
outPutImageName="_"+imageName

hk=open(imageName,"rb")
tm=hk.read()
ag=open(outPutImageName,'wb')
listp=list(password);
list1=list(tm)
k=0;
kt=0; 
for x in list1:
        i=int(x.encode('hex'),16)
        gudan=ord(listp[kt])%256
        kt=kt+1
        if kt>=len(listp):
        	kt=0
        t=(i+gudan)%256
        list1[k]=("%0.2X"%t).decode('hex')
        k=k+1;

strn=''.join(list1)

ag.write(strn);

