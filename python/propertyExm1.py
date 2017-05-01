#!/usr/bin/python
class Main:
    def __init__(self,name):
          self.__name = name

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self,name):
        self.__name = name



if __name__ == "__main__":
      x =  Main("haikent")
      x.name = "Aditi"
      print x.name
