def rs(s):
     s=list(s)
     a=len(s)-1
     i=0
     if a<=1:
        return str(s)
     while i<a:
        s[i],s[a]=s[a],s[i]
        a-=1
        i+=1
     ts=str()
     for x in s:
       ts+=x
     return ts



print rw("helloc fddfs ")

