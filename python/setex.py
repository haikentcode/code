#!/usr/bin/env python
N=input()
a=set(map(int,raw_input().split()))
M=input()
b=set(map(int,raw_input().split()))
sl=list(map(int,(a.union(b)).difference(a.intersection(b))))
sl.sort()
for k in sl:
    print k


