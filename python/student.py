class student:
  list=[{'name':'','rollno':'','mobileno':''}]
  def __init__(self,name,rollno,mobileno):
      self.name=name
      self.rollno=rollno
      self.mobileno=mobileno
      self.list+=[{'name':self.name,'rollno':self.rollno,'mobileno':self.mobileno}]


  def show(self):
    for student in self.list:
  		  print "%s\t%s\t%s" % (student['name'],student['rollno'],student['mobileno'])

  def search(self,tupl,key):
  			   for student in self.list:
  			      if student[tupl]==key:
  			         print "%s\t%s\t%s" % (student['name'],student['rollno'],student['mobileno'])		


while True:

 strng=raw_input().split()
 if strng[0]=="add":
	s1=student(strng[1],strng[2],strng[3])
 elif strng[0]=="show":
    	 s1.show()
 elif strng[0]=="search":
       print "%s\t%s\t%s"%("name","rollno","mobileno")
       s1.search(strng[1],strng[2])      
 elif print "command are -- add name rollno mobileno"      



	
	

       