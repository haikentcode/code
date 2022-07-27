
def f(n):
	if n<0:
	   return 0
	if n==1 or n==0:
	       return 1
	else:
	   return n*f(n-1)

def ncr(n,r):
    if n>r:
        return 0    
    return f(n)/(f(n-r)*f(r))


def npr(n,r):
	if n>r:
		return 0
	return f(n)/f(n-r)


