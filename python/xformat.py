
def sp(n):
   x=""
   for i in range(n):
      x+=" "
   return x

def printx(s):
   n=len(s)
   space=2**(n/2-1)+1
   bs=0
   for i in range(1,n+1):
       if i<=n/2:
         print sp(bs),i,sp(space),n-i+1
         if space==3:
              space=1
              bs+=1
         else:
              space-=2
              bs+=1
       elif i==n/2+1:
          print sp(bs+1),n/2+1
          space=0
          bs=2**(n/2-1)-1
       else:
            print "",


printx("hiteshxacs1")




