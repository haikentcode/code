"""
If a number n is prime then for a 1<=a<n

a^(n-1)=1(mod n)

"""
import sys
import math
import random
def power(x,y,m):
     ''' (x^y)%m '''
     x=x%m
     ans=1
     while y>0 :
         if y & 1 :
              ans=(ans*x)%m
         y=y>>1 #y=y/2
         x=(x*x) % m
     return ans

def log2Int(n):
       return int(math.log(n)/math.log(2)) 
   
def isPrime(n):
       k=log2Int(n)
       if n==1 or n==4:
            return False
       if n <= 3 :
            return True
       
       while k :
              r=random.randint(2,n-2)
              if not power(r,n-1,n)==1:
                   return False
       return True

if __name__=="__main__":
     if len(sys.argv)>1:
         print isPrime(int(sys.argv[1]))
     else:
        print "argumnet n prime test"


 
