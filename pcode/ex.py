import urllib2

sock = urllib2.urlopen("http://diveintopython.org/") 
htmlSource = sock.read()                            
sock.close()                                        
print htmlSource
