import requests
import json

api = "https://jsonmock.hackerrank.com/api/movies/search/?Title=%s&page=%d"

_txt = "spiderman"
_url = api%(_txt,1)
_res = requests.get(_url)



data = json.loads(_res.text)

pages =  data["total_pages"]

_list = map(lambda mv:mv["Title"],data["data"])
i = 2
while pages >=i:
    _url = api%(_txt,i)
    _res = requests.get(_url)
    data = json.loads(_res.text)
    _list += map(lambda mv:mv["Title"],data["data"])
    i+=1

_list.sort()
for mv in _list:
    print mv

