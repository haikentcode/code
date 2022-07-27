# <@ HIOS product >
# by Hitesh kumar regar 
# mapping b/w file1,file2,file3 data column 'Vender Sku Code' and 'Product Code'
# where file1,file2,file3 are pannel file
# 
#  |Delhivery Code        | Amazon Code | Flipkart |Jabong |
#  ---------------------------------------------------------
#  |process_commmon_code  | xyzpqrstuv  | abcdefgk | hknmuy|
#
# if you want to include product_specification in diff diff column 
#  than comment (#flag) line by adding # in starting of those line
# how to use 
#---------------------------Requirements--------------------------
# 1.Install Python.
# 2.install xlsxwriter 
# 3.install Tkinter 
# ---------------------------Step To Run--------------------------
# 1.Open Your Command Window
# 2.Reach The Location Of This file 
# 3.Run This FIle by using command: python thisfilename.py < eg. Dixcl(json to excel).py > 
#  GUI window popup(show) 
# -----------------------
# | windowname        X |
# |----------------------
# | {add file button  } | 
# | {Create Excel File} |
# |_____________________|
# 4.Add all csv file by using Add file button
# 5.after adding all file use 'Create Excel File' button to create Excel file
# 6.This Programe convert json data csv file into Excel file like ( if xyz.csv file input than xyz.csv.xcl file output)
# -----------------------------------------------------------------------------------------------------------------------
# if any quary contact us (hiteshnitj16@gmail.com )
#!/usr/bin/env python

import ast
import xlsxwriter
import sys
reload(sys)
sys.setdefaultencoding("utf-8") 
from Tkinter import *
from tkFileDialog import askopenfilename
from tkMessageBox import *

class  Dixcl:
  def __init__(self,ifname,ofname):
            self.keycol={}
            self.fileis=ifname
            self.outputfile=ofname
            sys.setdefaultencoding("utf-8")
            self.workbook = xlsxwriter.Workbook(ofname+'.xlsx')
            self.worksheet = self.workbook.add_worksheet()
            self.companySKUCode=['ASIN','SUPC','FSN'] # add Here if you another SKU 

  def addTosheet(self,dic,r):
          c=0
          for key,val in dic.items():
               self.addItem(key,val,r,c)
               c+=1

  def addItem(self,key,val,row,c):
              if key not in self.keycol.keys():
                 self.keycol[str(key)]=len(self.keycol)
                 self.worksheet.write(0,self.keycol[str(key)],str(key))
                 print "new key added->",key
              val=str(val).replace("\n"," ").replace("  "," ")
              if str(key)=="product_specifications" :
                   psd=ast.literal_eval(str(val))
                   lists=psd.items()
                   psd2=lists[0][1]
                   strr=""
                   for a in psd2:
                    if a['key'] in self.companySKUCode: #flag
                       if a['key'] not in self.keycol:
                           print "new specific key found:",a['key'] 
                           self.keycol[a['key']]=len(self.keycol)
                           self.worksheet.write(0,self.keycol[a['key']],str(a['key']))
                       self.worksheet.write(row,self.keycol[str(a['key'])],a['value'])
                    else:#flag
                        if  self.keycol.get(str(a['key']),True):
                                  self.keycol[str(a['key'])]=len(self.keycol)
                        self.worksheet.write(0,self.keycol[str(a['key'])],str(a['value']))
                    self.worksheet.write(row,self.keycol[str(key)],strr) #flag
              else:
                self.worksheet.write(row,self.keycol[str(key)],val)
  def makeColumn(self,dic):
    if type(dic) is dict: 
     for key,value in dic.items():
        if  not str(key)=="product_specifications":
            print key
            self.keycol[key]=len(self.keycol)
            self.worksheet.write(0,self.keycol[str(key)],str(key))
     self.keycol["product_specifications"]=len(self.keycol)
     self.worksheet.write(0,self.keycol["product_specifications"],str("product_specifications"))

  def start(self):
            fp=open(self.fileis)
            error=" "
            r=1
            for i, line in enumerate(fp):
              try:
                print i
                if len(line)>10:
                    line=line.replace("\"\"","\"")
                    line=line.replace("\"{","{")
                    line=line.replace("}\"","}")
                    if len(self.keycol)==0:
                      self.makeColumn(ast.literal_eval(line))
                    self.addTosheet(ast.literal_eval(line),r)
                r +=1    
              except:
                  print "Exception acr"
                  pass
            print "saving file ..........."      
            self.workbook.close()
            print "file saved"
class GUI(Frame):
  def __init__(self,master=None):
     Frame.__init__(self,master)
     self.createGUI()
     self.pack()
     self.filelist=[]
  def createGUI(self):
       Button(text='Add File', command=self.addfile).pack(fill=X)
       Button(text='Create Excel File', command=self.createXlfile).pack(fill=X)
  def addfile(self):
     fname=askopenfilename()
     if len(fname)>0:
       self.filelist.append(fname)
  def createXlfile(self):
    for fileis in self.filelist:
      if len(fileis)>0:
        h=Dixcl(fileis,fileis.split("\\")[-1])
        h.start()
      showinfo(title=None,message="Files Saved") 

if __name__=="__main__":
   tk=Tk()
   obj=GUI(tk)
   obj.mainloop()
   tk.destroy()
