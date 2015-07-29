def lps(s):
   c=0
   for i in range(len(s)):
     for j in range(i,len(s)):
           s1=s[i:j+1]
           s2=s1[::-1]
           if s1==s2:
                if (c<len(s1)):
                        c=len(s1)
   return c  
           
s=raw_input()
print lps(s)


