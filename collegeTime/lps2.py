def lps2(s):
 t=[[False for x in range(len(s))] for x in range(len(s))]
 for x in range(len(s)):
   t[x][x]=True
 maxlen=1
 start=0
 n=len(s) 
 for x in range(n-1):
    if s[x]==s[x+1]:
         t[x][x+1]=True
         maxlen=2
         start=x
 for k in range(3,n):
   for i in range(0,n-k):
       j=i+k-1
       if t[i+1][j-1]==True & (s[i]==s[j]):
         t[i][j]=True
         #print "d"
         if k>maxlen: 
            maklen=k
            start=i
            #print "l"
 print start
 print maxlen


lps2(raw_input())
