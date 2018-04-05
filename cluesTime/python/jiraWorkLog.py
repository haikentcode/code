import requests
import json
import sys

class JiraAPI:
    def __init__(self,issue):
        self.issue = issue
        self.domain = "http://jira.shopclues.com/"
        self.worklog = "rest/api/2/issue/%s/worklog"
        self.user = 'C2047'
        self.password = "******"

    def get(self,url):
        r = requests.get(url, auth=(self.user,self.password))
        data = json.loads(r.text)
        return data

    def getWorkLogs(self):
        url = self.domain+(self.worklog%self.issue)
        for log in self.get(url)["worklogs"]:
            print log["comment"]



if __name__ == "__main__":
      if len(sys.argv) > 1:
          print sys.argv[1]

      j = JiraAPI("cic-1965")
      j.getWorkLogs()
