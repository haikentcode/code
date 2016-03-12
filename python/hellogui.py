#!/usr/bin/env python
import Tkinter 
import tkMessageBox

top=Tkinter.Tk();

def loveYou():
	tkMessageBox.showinfo("For My Baby","I love You Baby")

B=Tkinter.Button(top,text="hello",command=loveYou)

B.pack()
top.mainloop()

