import urllib
file = urllib.urlopen('http://www.google.com')
print file.read()
