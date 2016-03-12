import re
def matrixInput(N):
    l=[]
    for i in range(N):
        s=raw_input()
        intlist=[int(x) for x in re.split(r'[\s]*',s)]
        l.append(intlist)
    return l;

def showMatrix(m):
     print m
N=input()
m=matrixInput(N)
showMatrix(m)
LeftDaigonal=0
RightDaigonal=0
for i in range(N):
  for j in range(N):
      if i==j:
            LeftDaigonal+=m[i][j]
      if i+j==N-1:
            RightDaigonal+=m[i][j]


print abs(LeftDaigonal-RightDaigonal)


