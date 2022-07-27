import math
def lps(s):
     n=len(s)
     table=[[False for j in range(n)] for i in range(n)]
     
     for i in range(n):
	table[i][i]=True
	start=0;
	length=1;
     for i in range(0,n-1,2):
       if s[i]==s[i+1]:
          table[i][i+1]=True
          start=i
          length=2
     for k in range(2,n+1):
       for i in range(0,n-k+1):
    	  j=i+k-1
    	  if s[i]==s[j] and table[i+1][j-1]:
    		table[i][j]=True
    		if k>length:
                   start=i
    		   length=k
     return s[start:start+length]
    

print lps(raw_input())
