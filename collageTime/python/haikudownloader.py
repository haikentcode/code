from pattern.web import URL


url1='http://results.indiaresults.com/rj/mdsu/result.aspx?__EVENTTARGET=&__EVENTARGUMENT=&__VIEWSTATE=%2FwEPDwUKMTU5OTg1ODM2Nw9kFgpmDxYCHgRUZXh0BawBPG1ldGEgbmFtZT0iZGVzY3JpcHRpb24iIGNvbnRlbnQ9IlNlYXJjaGluZyBmb3IgeW91ciBNRFMgVW5pdmVyc2l0eSBCLkMuQS4gUGFydCBJSUkgRXhhbSBSZXN1bHQgMjAxNSAgdGhlbiBkbyB2aXNpdCBJbmRpYVJlc3VsdHMuY29tLCBsZWFkaW5nIG9ubGluZSBleGFtIHJlc3VsdCBwb3J0YWwuIiAvPmQCAQ8PFgIfAAWqAjxhIGhyZWY9J2h0dHA6Ly93d3cuaW5kaWFyZXN1bHRzLmNvbScgY2xhc3M9J0luZGlhUmVzdWx0czExYmxhY2tiJz5Ib21lPC9hPiZuYnNwOz4%2BJm5ic3A7PGEgY2xhc3M9J0luZGlhUmVzdWx0czExYmxhY2tiJyBocmVmPSdodHRwOi8vcmFqYXN0aGFuLmluZGlhcmVzdWx0cy5jb20vRGVmYXVsdC5hc3B4Jz5SYWphc3RoYW48L2E%2BJm5ic3A7Pj4mbmJzcDs8YSBjbGFzcz0nSW5kaWFSZXN1bHRzMTFibGFja2InIGhyZWY9J2h0dHA6Ly9yYWphc3RoYW4uaW5kaWFyZXN1bHRzLmNvbS9tZHN1Jz5NRFMgVW5pdmVyc2l0eTwvYT5kZAICDw8WBh4ISW1hZ2VVcmwFHi4uLy4uLy4uL2xvZ29zL3VuaXZsb2dvTURTLnBuZx4HVG9vbFRpcAUOTURTIFVuaXZlcnNpdHkeB1Zpc2libGVnZGQCAw8PFgQfAAUOTURTIFVuaXZlcnNpdHkfA2dkZAIEDw8WBB8ABSFCLkMuQS4gUGFydCBJSUkgRXhhbSBSZXN1bHQgMjAxNSAfA2dkZGTtArkyGfXqSIIuml%2FemCXpJo49eZEzQ0yIa9x5PwKEWg%3D%3D&__PREVIOUSPAGE=PtvVom57yrqea6jnAbQuAWL-GuAQMKq65ms_EWQXN1VdZ8S2VQLgMKYAkg0d0pvhCJqPupD5I7QHhhIka0q3z06YalplFXaj1rjetyXnff41&__EVENTVALIDATION=%2FwEdAAaJ4nZkKCTB2VmEVz%2BL%2BtpReTRTGp1BjlPMQ9CB5yf1ipHDSqSIg%2B%2FCalu1wP18WWujOglmm5fGSk5UkpFsfK4e75P%2BcglUsqFmnlFUIL7QeUzJ3Cp9XRV2eZZECg0xYOLJI8TjBir2aHdJOxwp2xBHAq9SRktk3lixhszVyv7SLg%3D%3D&RollNo='
url2='&btnRoll=Find+Results&txtName=&id=1000177685'

#url1='http://urbehouse.com/us/rip_us/images/62931186'
#url2='.jpg'
for i in range(38100,38999):
        try: 
             url=URL(url1+str(i)+url2)
             i=i+1
             x=url.download()
             f=open(str(i)+url2,'wb')
             f.write(x)
        except:
        	 print url
        	 continue
        

