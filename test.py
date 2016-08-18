
import re
ls=raw_input()
ls=re.split(r'[\s]*',ls)
n=int(ls[0])
k=int(ls[1])

def eratosthenes2(n):
    multiples = set()
    for i in range(2, n+1):
        if i not in multiples:
            yield i
            multiples.update(range(i*i, n+1, i))

print "list done"

l=list(eratosthenes2(n))

def count(n,k,l):
  x=0
  for i in range(len(l)):
  	if x>k:
  	  break
  	if l[i]>n:
  		break
  	elif n%l[i]==0:
  		x+=l[i]
  return x		
   
   
   
sum=0
i=k
j=0
while i<=n:
  if count(i,k,l)==k:
	 sum+=1
  i=k+l[j]
  j+=1
    
print sum		
