#!/usr/local/bin/python3

from multiprocessing import Pool
from urllib.request import urlopen
import xmltodict

#image

class Tree:
    def __init__(self,id,rawData={}):
        self.id = id
        self.api = "http://imagenet.stanford.edu/python/tree.py/SubtreeXML"
        if rawData:
            self.infoFromRawData(rawData)
        else:
            self.infoFromURL()

        self.name = self.rawInfo["@words"]
        self.gloss = self.rawInfo["@gloss"]
        self.size = int(self.rawInfo["@num_children"])


    def  infoFromRawData(self,rawData):
        self.rawInfo = rawData

    def __str__(self):
        return str(self.id)+"=>{name='"+str(self.name)+"' size="+str(self.size)+" }"

    def urlToData(self,url):
            xmlPage = urlopen(url).read()
            return  xmltodict.parse(xmlPage)

    def infoFromURL(self):
        url = self.api+"?rootid="+str(self.id)+"&targetid="+str(self.id)
        rawData = self.urlToData(url)
        self.rawInfo = rawData["synset"]


    def childs(self):
        url = self.api+"?rootid="+str(self.id)
        data =  self.urlToData(url)
        if "synset" in data["synset"]:
            rawChildList = list(data["synset"]["synset"])
        else:
            rawChildList = []
        return map(lambda node:Tree(int(node["@synsetid"]),node),rawChildList)


tree = Tree(82127)
print(tree)
for child in tree.childs():
    print(child)
