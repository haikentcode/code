#!/usr/bin/python
# spider pageg demo
import sys
import urlparse
import urllib
from pymongo import MongoClient
from bs4 import BeautifulSoup


client=MongoClient()
db=client.haios
urllist=db.urllist
url="http://www.zdwired.com/sites-to-download-free-hd-wallpapers/"
urls=[url] #stack of urls to scrape
visited=[url] #historic record of urls

while len(urls)>0:
	try:
	   html=urllib.urlopen(urls[0])
	   htmltext=html.read()
	except:
	   print "error in opening url=",urls[0]
	soup=BeautifulSoup(htmltext)
	urls.pop(0)
	print len(urls),len(visited)
	for tag in soup.findAll('a',href=True):
		tag["href"]=urlparse.urljoin(url,tag["href"])
		if  tag["href"] not in visited:
			  print tag["href"]
			  urllist.insert_one({"url":tag["href"]})
			  urls.append(tag["href"])
			  visited.append(tag["href"])
		
print "The end of  visiting and collectiong stuf are"
print "total urls",len(visited)
print "urls are"
print visited