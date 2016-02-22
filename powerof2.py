
def mylog(n):
     if n > 0:
        return mylog(n/2)+1
     return 0 

n=input()

print 2**mylog(n)


