s=open("2.txt").read()
from collections import OrderedDict
foo = s
print "".join(OrderedDict.fromkeys(foo))
