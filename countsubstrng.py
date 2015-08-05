#!/usr/bin/env python
s=raw_input()
d=raw_input()

counter=0
for i in range(0,len(s)):
    if s[i]==d[0]:
        flag=True
        for j in range(1,len(d)):
            if (i+j< len(s)):
                if (s[i+j]!=d[j]):
                    flag=False
                    break
            else:
                flag=False        
        if flag==True:
            counter=counter+1
print counter
        
            