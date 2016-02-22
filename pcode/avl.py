#An AVL tree node
class Node:
    def __init__(self):
        self.key=int()
        self.left=None
        self.right=None
        self.height=int()
        self.size=int()


class AVL:
    def __init__(self):
        self.root=None

    def newNode(self,key):
        node=Node()
        node.height=1
        node.key=key
        node.size=1
        return node

    def getHeight(self,node):
        if node:
            return node.height
        else:
            return 0

    def getSize(self,node):
        if node:
            return node.size
        else:
            return 0

    def rightRotate(self,y):
          x=y.left
          T2=x.right

          #Perform rotation
          x.right=y
          y.left=T2

          #update height
          y.height=max(self.getHeight(y.left),self.getHeight(y.right))+1
          x.height=max(self.getHeight(x.left),self.getHeight(x.right))+1

          #update size
          y.size=self.getSize(y.left)+self.getSize(y.right)+1
          x.size=self.getSize(x.left)+self.getSize(x.right)+1

          return x

    def leftRotate(self,x):
        y=x.right
        T2=y.left

        #Perform rotation
        y.left=x
        x.right=T2

        #update height
        x.height=max(self.getHeight(x.left),self.getHeight(x.right))+1
        y.height=max(self.getHeight(y.left),self.getHeight(y.right))+1

        #update size
        x.size=self.getSize(x.left)+self.getSize(x.right)+1
        y.size=self.getSize(y.left)+self.getSize(y.right)+1

        return y

    def getBalance(self,node):
        if node:
            return self.getHeight(node.left)-self.getHeight(node.right)
        else:
            return 0

    def insert(self,node,key,count):
           # 1.Perform the normal BST rotation
           if not node:
               return self.root
           if key < node.key:
               node.left=self.insert(node.left,key,count)
           else:
               node.right=self.insert(node.right,key,count)
               count[0]=count[0]+self.getSize(node.left)+1

           #2. Update height and size of this ancestor node
           node.height=max(self.getHeight(node.left),self.getHeight(node.right))+1
           node.size=self.getSize(node.left)+self.getSize(node.right)+1

           #3. Get the balance factor of this ancestor node to check whether this node became unbalanced
           balance=self.getBalance(node)

           # Left Left Case
           if balance >1 and key < node.left.key:
                 return self.rightRotate(node)

           # Right Right Case
           if balance < -1 and key > node.right.key:
                 return self.leftRotate(node)

           # Left Right Case
           if balance > 1 and key > node.left.key:
                       node.left=self.leftRotate(node.left)
                       return rightRotate(node)
           # Right Left Case
           if balance < -1 and key < node.right.key:
               node.right=self.rightRotate(node.right)
               return leftRotate(node)

           return node


#The following function updates the countSmaller array to contain count of
#smaller elements on right side.
def constructLowerArray(arr,countSmaller):
     avltree=AVL()
     for i,x in  enumerate(arr):
        a=[0]
        avltree.root=avltree.insert(avltree.root,x,a)
        countSmaller[i]=a[0]



def main():
    arr=[10, 6, 15, 20, 30, 5, 7]
    #ans 3 1 2 2 2 0 0
    n = len(arr)
    low=[0]*n
    constructLowerArray(arr,low);
    for x in low:
        print x,

if __name__ == "__main__":
       main()
