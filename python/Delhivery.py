d={}
import ast
with open('ds.txt','r') as f:
  for line in f:
     d=ast.literal_eval(line)
     print d.keys()