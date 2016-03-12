def cal(l):
  sum=0
  for i in range(len(l)-1):
    if int(l[i]+l[i+1]) <=26:
             tl=[]
             tl.extend(l[i]+l[i+1])
             tl.extend(l[i+2:])
             a=cal(tl)
             sum=sum+1+a
  return sum


if __name__=="__main__":
  a=raw_input()
  l=[x for x in a]
  sum=cal(l)
  print(sum)

