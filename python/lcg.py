a=input("value of a=")
m=input("value of m=")
c=input("value of c=")
x=input("initial value of x")
n=input("no of random number to print")


for i in range(n):
   x=(a*x+c)%m
   print x

