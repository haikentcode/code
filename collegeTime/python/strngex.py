#!/usr/bin/env python
def haiku(s,i,c):
    print s[:i]+c+s[i+1:]
s=raw_input()
a,b=raw_input().split()
a=int(a)
haiku(s,a,b)