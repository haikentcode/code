import time


def stepCount(n):
    step=1
    while n !=1:
        step+=1
        if n%2 ==0:
            n=n/2
        else:
            n=3*n+1
    return step


if __name__ =="__main__":
        T=input()
        test = [raw_input().split(" ") for i in range(T)]
        t1 = time.time()

        for i,j in test:
                _maxStep = max([stepCount(n) for n in range(int(i),int(j)+1)])
                print i,j,_maxStep
        t2 = time.time()

        print "time",t2-t1        
