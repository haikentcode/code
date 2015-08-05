import re

for i in range(10000000):
  try:
       print sum([ int(x) for x in re.split(r'[\s]',raw_input())])
       print "\n"
  except:
     print "invalid input"
