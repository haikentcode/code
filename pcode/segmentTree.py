import math

def log2(n):
    return math.log(n)/math.log(2)

class segmentTree:
    '''segment tree update and get sum in range'''
    def __init__(self):
         self.arr=[]
         self.st=[]

    def construct(self,arr):
        self.arr=arr
        n=len(arr)
        x=int(math.ceil(log2(n)))
        self.st=[0]*(2*2**x-1)
        self.constructUtil(0,n-1,0)
    def constructUtil(self,ss,se,si):
        if ss==se:
            self.st[si]=self.arr[ss]
            return self.arr[ss]
        mid=(ss+se)/2
        self.st[si]=self.constructUtil(ss,mid,si*2+1)+self.constructUtil(mid+1,se,si*2+2)
        return self.st[si]

    def getSumUtil(self,ss,se,qs,qe,si):
        if qs <= ss and qe >= se:
            return self.st[si]
        if se < qs or ss > qe :
            return 0
        mid=(ss+se)/2
        return self.getSumUtil(ss,mid,qs,qe,2*si+1)+self.getSumUtil(mid+1,se,qs,qe,2*si+2)


    def getSum(self,qs,qe): # sum(arr[qs:qe])
            n=len(self.arr)
            if qs<0 or qe > n-1 or qe < qs :
                  print "Invalid Range"
                  return -1
            return self.getSumUtil(0,n-1,qs,qe,0)

    def updateUtil(self,ss,se,index,diff):
            if index >=ss and index <=se :
               self.st[index]=self.st[index]+diff
               if not se==ss :
                  mid=(ss+se)/2
                  self.updateUtil(ss,mid,index*2+1,diff)
                  self.updateUtil(mid+1,se,index*2+2,diff)

    def update(self,index,newValue):
          n=len(self.arr)
          if index < 0 or index > n-1 :
              print "Invalid Index"
          diff=newValue-self.arr[index]
          self.arr[index]+=diff
          self.updateUtil(0,n-1,index,diff)


    def test(self):
          print self.st

if __name__=="__main__":
      st=segmentTree()
      arr=[1, 3, 5, 7, 9, 11]
      st.construct(arr)
      st.test()
      print st.getSum(1,3)
      st.update(1,10)
      print st.getSum(1,3)
