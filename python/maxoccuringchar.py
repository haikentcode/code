s=raw_input()
counter={}
maxc=None
for x in s:
     counter[x]=counter.get(x,0)+1
     if not maxc:
          maxc=(x,1) 
     if maxc and maxc[1] <  counter.get(x):
          maxc=(x,counter.get(x))
     
print maxc
