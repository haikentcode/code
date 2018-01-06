#!/usr/bin/env python
N=input()
strng=raw_input().split()
Dic=[{'name':strng[0],'marks':(int(strng[1]),int(strng[2]),int(strng[3]))}]
for a in range(1,N):
    strng=raw_input().split()
    Dic+=[{'name':strng[0],'marks':(int(strng[1]),int(strng[2]),int(strng[3]))}]
    
name=raw_input()

for a in Dic:
    if a['name']==name:
        print a['marks'][0]+a['marks'][1]+a['marks'][2]/3n