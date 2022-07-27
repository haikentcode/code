import matplotlib.pyplot as plt 

a,b,c,d=(12.4,1.2,1.0,0.9)

pprev=1.0
D=a-b*pprev
S=c+d*pprev

print "P\t\tS\t\tD"

print "%f\t%f\t%f" % (pprev,S,D)


pl=[]
dl=[]
sl=[]
for i in range(10):
     p=(a-c-d*pprev)/b
     D=a-b*p
     S=c+d*p
     pl.append(p)
     dl.append(D)
     sl.append(S)
     print "%f\t%f\t%f" % (p,S,D)
     pprev=p



plt.plot(pl,sl)
plt.plot(pl,dl)
plt.axis([0,12,0,10])
plt.show()
