#!/usr/bin/env python

import Tkinter
import tkMessageBox

def submit():
	tkMessageBox.showinfo("Msg for you","who are you")

top=Tkinter.Tk();

L1=Tkinter.Label(top,text="User Name")
L1.pack()

E1=Tkinter.Entry(top,bd=1)
E1.pack()

L2=Tkinter.Label(top,text="User Password")
L2.pack()

E2=Tkinter.Entry(top,bd=1)
E2.pack()

B=Tkinter.Button(top,text="submit",command=submit)
B.pack();

top.mainloop()