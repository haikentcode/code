s=open("1.txt").read()

ns=""

for x in s:
     if ord(x) >= ord('a') and ord(x) <= ord('z'):
             ns+=chr(ord(x)+2)
     else:
         ns+=x


ns=ns.replace("{","a").replace("|","b")

print ns
