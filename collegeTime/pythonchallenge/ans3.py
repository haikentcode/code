s = open("3.txt").read()



j=0
for i in range(len(s)):
   
     if ord(s[i]) > ord('A') and ord(s[i]) < ord('Z'):
            j+=1
     else:
            j=0
     
     if j==3:
         while i < len(s) and (

     
