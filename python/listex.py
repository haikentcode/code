#!/usr/bin/env python
N=input()
L=[]
for a in range(0,N):
    strng=raw_input().split();
    action=strng[0]
    if action=="insert":
        L.insert(int(strng[1]),int(strng[2]))
    elif action=="print":
        print L
    elif action=="append":
        L.append(int(strng[1]))
    elif action=="sort":
        L.sort()
    elif action=="pop":
        L.pop()
    elif action=="reverse":
        L.reverse()
    elif action=="remove":
        L.remove(int(strng[1]))
    elif action=="index":
        L.index(int(strng[1]))
 

        
    