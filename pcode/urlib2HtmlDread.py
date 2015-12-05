import urllib
fhand=urllib.urlopen('https://wordpress.org/')
for line in fhand:
       print line.strip()

