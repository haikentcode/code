
def gcd(a,b):
    #    if a==0:
    #         return b
    #   return gcd(b%a,a)
    return agcd(a,b)


def agcdUtil(a,b,p):
    if a==0:
       p[0]=0
       p[1]=1
       return b
    ans=agcdUtil(b%a,a,p)
    x=p[1]-int(b/a)*p[0]
    y=p[0]
    p[0]=x
    p[1]=y
    return ans

def agcd(a,b):
      point=[0,0]
      return agcdUtil(a,b,point)


def lcm(A):
        """
         #two
         lcm(a,b) = a*b /gcd(a,b)
        _______________________________
         #list
         x = A0
         lcm(A) = L[1:n-1] {Ai*x/gcd(Ai*x)=>x}
         # A list , Ai i'th in list ,L loop
        """
        x=A.pop(0)
        for a in A:
             x = a*x/gcd(a,x)

        return x

if __name__ == "__main__":
     a=[2, 7, 3, 9, 4]
     print lcm(a) #252
