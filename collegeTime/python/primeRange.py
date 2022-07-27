import math
import sys
class primRange:
    def __init__(self):
         pass

    def eratosthenes(self,s,n):
          p=[True]*(n+1)
          p[0]=False
          p[1]=False
          i=2
          while i<=n:
              if p[i] :
                  if i >=s:
                         print i
                  j=i       
                  while j<n:
                       p[j]=False
                       j+=i
              i+=1         



if  __name__=="__main__":
        t=input()
        pr=primRange()
        while t:
            t-=1
            l=map(int,raw_input().split(" "))
            pr.eratosthenes(l[0],l[1])
            print ""
