class Node:
   def __init__(self):     
     self.data=None
     self.left=None
     self.right=None
   def getLeft(self): return self.left
   def getRight(self): return self.right
   def getData(self): return self.data
   def Left(self,d):
      self.left=d
   def Right(self,d):
      self.right=d
   def Data(self,d):
      self.data=d

n=Node()
n.Data("hitesh")

a=Node()
a.Data("aditi")

b=Node()
b.Data("gudan")

n.Left(a)
n.Right(b)


print "     ",n.getData()
print "    /     \  "
print n.getLeft().getData(),"   ", n.getRight().getData()

