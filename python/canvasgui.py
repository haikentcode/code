#!/usr/bin/env python

import Tkinter
import tkMessageBox
import time
top=Tkinter.Tk()

def hkb(x,y,r,c):
	oval=c.create_oval(x,y,r,r,fill="orange")



C=Tkinter.Canvas(top,bg="yellow",height=300,width=400)
coord=10,40,80,140
arc=C.create_arc(coord,start=0,extent=150,fill="green")
oval=C.create_oval(200,200,50,80,fill="orange")
ball=C.create_oval(10,10,10,10,fill="pink")

C.pack()
top.mainloop()

