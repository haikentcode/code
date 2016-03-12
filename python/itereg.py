class Reverse:
   def __init__(self,data):
     self.data=data
     self.index=len(data)
   def __iter__(self):
     return self
   def __next__(self):
      if self.index==0:
             raise StopIteration
      self.index=self.index-1
      return self.data[self.index]
   next=__next__
   iter=__iter__


if __name__=="__main__":
  s=Reverse("aditi hitesh")
  for a in s:
     print a


