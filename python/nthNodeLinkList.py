class Node:
     def __init__(self,data=""):
           self.data=data
           self.link=None
         

class LinkList:
        def __init__(self,head=None):
               self.head=head
               self.leaf=None
               self.counter=0

        def insert(self,data):
              self.counter+=1
              if self.head:
                   self.leaf.link=Node(data)
                   self.leaf=self.leaf.link
              else:
                    self.head=Node(data)
                    self.leaf=self.head
        
        def delete(self,data):
              th=self.head
              if th and th.data==data:
                      tm=th.link
                      del th
                      self.head=tm
                      self.counter-=1
                      return
              while th.link and not th.link.data==data:
                      th=th.link
              if th.link:
                  tm=th.link
                  th.link=th.link.link
                  if not th.link:
                          th.leaf=th
                  del tm
                  self.counter-=1

              return
        def  __len__(self): #len(classObj)
              return self.counter
       
        def __str__(self):  # when print 
               nodes=""
               th=self.head
               while th:
                  nodes+=str(th.data)+" "
                  th=th.link
               return nodes.strip()
                               

if __name__ == "__main__":
     mylist=LinkList()
     mylist.insert("hitesh")
     mylist.insert("aditi")
     mylist.insert("alisha")
     mylist.insert("gudan")
     mylist.insert("angel")
     print mylist
     mylist.delete("alisha")
     print mylist     
     print len(mylist)_
               
