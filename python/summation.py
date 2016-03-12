a=[1,2,3,4,5,6,7,8,9,10]
b=input()
i=0
j=len(a)-1
while i<j:
   if a[i]+a[j]<b:
         i+=1
   elif a[i]+a[j]>b:
         j-=1
   else:
       print a[i],a[j]
       i+=1
       j-=1
print "done"
