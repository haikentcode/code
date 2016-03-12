import math
class Complex:
    def __init__(self,a=0.0,b=0.0):
        self.a=a
        self.b=b
    def __add__(self,other):
        r=Complex(self.a+other.a,self.b+other.b)
        return r
    def __sub__(self,other):
        r=Complex(self.a-other.a,self.b-other.b)
        return r
    
    def __mul__(self,other):
        r=Complex(float(self.a*other.a-self.b*other.b),float(self.a*other.b+self.b*other.a))
        return r
    def __div__(self,other):
        r=Complex((self.a*other.b+self.b*other.b)/(other.a*other.a+other.b*other.b),(self.b*other.a-self.a*other.b)/(other.a*other.a+other.b*other.b))
        return r
    
    def show(self):
        if self.b<0:
            print "%0.2f - %0.2fi" %(float(self.a),-float(self.b))
        else:
            print "%0.2f + %0.2fi" %(float(self.a),float(self.b))    

        
    def  MOD(self):
            print "%0.2f" % (float(math.sqrt(self.a*self.a+self.b*self.b)))    
    
    
if __name__=="__main__":
    a=raw_input().split(" ")
    b=raw_input().split(" ")
    A=Complex(float(a[0]),float(a[1]))
    B=Complex(float(b[0]),float(b[1]))
    C=Complex(0,0)
    C=A+B
    C.show()
    C=A-B
    C.show()
    C=A*B
    C.show()
    C=A/B
    C.show()
    A.MOD()
    B.MOD()