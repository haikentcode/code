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
