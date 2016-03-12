def maxSubArray(A):
       if len(A)==0:
           return A
       temSum=maxSum=A[0]
       start=finish=i=0
       
       for j in range(1,len(A)):
             if A[j] >(temSum+A[j]):
                     temSum=A[j]
                     i=j
             else:
                    temSum+=A[j]
              
             if temSum > maxSum:
                    maxSum=temSum
                    start=i
                    finish=j
       return A[start:finish+1]




print maxSubArray(map(int,raw_input().split(" ")))


