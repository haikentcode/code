s=raw_input()
myhash={}
ns=""
for x in s:
   if myhash.get(x,None):
        continue
   else:
        myhash[x]=True
        ns+=x

print ns
