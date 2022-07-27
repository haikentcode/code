import math
class Coordinate:
    def __init__(self,t):
           self.x=t[0]
           self.y=t[1]
           self.z=t[2]
    def ab(self,b):
         return (b.x-self.x,b.y-self.y,b.z-self.z)
    
class Vector:
    def __init__(self,v):
          self.v=v
    def  __add__(self,other):
        return Vector((self.v[i]+other.v[i] for i in range(3)))
    def  __sub__(self,other):
        return Vector((self.v[i]-other.v[i] for i in range(3)))
    def dot(self,other):
        return sum(self.v[i]*other.v[i] for i in range(3))
    def cros(self,other):
        return Vector((self.v[1]*other.v[2]-self.v[2]*other.v[1],self.v[2]*other.v[0]-self.v[0]*other.v[2],self.v[0]*other.v[1]-self.v[1]*other.v[0]))
    def length(self):
        return math.sqrt(self.dot(self))
def Cinput():
    return Coordinate(tuple(map(float,raw_input().split(" "))))
A=Cinput()
B=Cinput()
C=Cinput()
D=Cinput()
AB=Vector(A.ab(B))
BC=Vector(B.ab(C))
CD=Vector(C.ab(D))
X=AB.cros(BC)
Y=BC.cros(CD)
XdotY=X.dot(Y)
xl=X.length()
yl=Y.length()

phi=XdotY/(xl*yl)

print phi



