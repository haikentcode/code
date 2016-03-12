#!/usr/bin/python
#-*- coding: utf-8 -*-

import sys
from PyQt4 import QtGui
def main():
   app=QtGui.QApplication(sys.argv)
   w=QtGui.QWidget()
   w.resize(300,300)
   w.setWindowTitle("HAIOS")
   w.show()
   sys.exit(app.exec_())

if __name__ == '__main__'  :
    main()
