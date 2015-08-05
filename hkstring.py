import sys
def hkprint(s):
       n=len(s)
       n2=n/2
       for i in range(n/2):
          for x in range(i+1):
               print "",
          sys.stdout.write(s[i])
          for x in range((n2-i)*2):
               print "",
          sys.stdout.write(s[n-i-1])
          print ""
       for i in range(n/2):
             print "",
       print s[n/2]
       for i in range(n/2):
           for x in range(n/2-i):
               print "",
           sys.stdout.write(s[n/2+












            .i-1])     

                
       
 
if __name__=="__main__":
  hkprint(raw_input())
