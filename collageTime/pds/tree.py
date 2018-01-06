class Node:
    def __init__(self,value=""):
        self.value=value
        self.left=""
        self.right=""
    def left(self):
        return self.left
    def right(self):
        return self.right
    def value(self):
        return self.value


class bst:
    def __init__(self):
        self.root=""
    def insert(self,value):
         if self.root=="":
             self.root=Node(value)
         else:
             self.rec(self.root,value)
    def  rec(self,root,value):
       if root.value < value :
           if root.left=="":
               root.left=Node(value)
           else:
               self.rec(root.left,value)
       else:
           if root.right == "" :
               root.right = Node(value)
           else:
               self.rec(root.right,value)

    def traverse(self):
            self.rect(self.root)
    def rect(self,node):
           if not node == "" :
               self.rect(node.left)
               print node.value
               self.rect(node.right)
    def find(self,key):
         self.recfind(self.root,key)
    def recfind(self,nd,key):
        if nd :
            if nd.value < key :
                self.recfind(nd.left,key)
            elif nd.value > key :
                self.recfind (nd.right,key)
            else:
                print "found key"
                return True




if __name__ == "__main__":
        tree=bst()
        tree.insert("hitesh")
        tree.insert("aditi")
        tree.insert("gudan")
        tree.insert("baby")
        tree.insert("angel")
        tree.insert("haikent")
        tree.insert("haios")
        tree.insert("HAA")
        tree.traverse()
        tree.find("HA")
