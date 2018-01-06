def mini(l,left,right):
   minm=l[left]
   mi=left
   for x in range(left,right):
      if l[x]<minm:
          minm=l[x]
          mi=x
   return mi

def maxi(l,left,right):
    maxm=l[left]
    mi=left
    for x in range(left,right):
      if l[x]>maxm:
         maxm=l[x]
         mi=x
    return mi

          

def stock(l,left,right):
   if(left+1==right):
        return (0,left,left)
   mid=left+(right-left)/2
   pl,dil,sil=stock(l,left,mid)
   pr,dirr,sir=stock(l,mid,right)
   minLeft=mini(l,left,mid)
   maxRight=maxi(l,mid,right)
   profit=l[maxRight]-l[minLeft]
   if(pl>max([pr,profit])):
        return (pl,dil,sil)
   elif(pr>max([pl,profit])):
        return (pr,dirr,sir)
   else:
        return (profit,minLeft,maxRight)

s=raw_input()
l=[int(x) for x in s.split(" ")]
print stock(l,0,len(l))

