/*
n=1
1 2
3 4
n=2 (spacing for clarity)
1  2  5  6
3  4  7  8
9  10 13 14
11 12 15 16
n=3 (spacing for clarity)
1  2  5  6  17 18 21 22 
3  4  7  8  19 20 23 24 
9  10 13 14 25 26 29 30 
11 12 15 16 27 28 31 32 
33 34 37 38 49 50 53 54 
35 36 39 40 51 52 55 56 
41 42 45 46 57 58 61 62 
43 44 47 48 59 60 63 64
*/


#include <iostream>
#include<cmath>
using namespace std;


int A[1024][1024];
void splidem(int n,int s,int a,int b){
	
	if(n>1){
		
	    int p=pow(2,n-1)*pow(2,n-1);
	    int k=pow(2,n)/2;
	    splidem(n-1,s,a,b);
	    splidem(n-1,s+p,a,b+k);
	    splidem(n-1,s+p*2,a+k,b);
	    splidem(n-1,s+p*3,a+k,b+k);
	    
		
	}
	 else if(n==1){
	   
	     A[a][b]=s;
	     A[a][b+1]=s+1;
	     A[a+1][b]=s+2;
	 	 A[a+1][b+1]=s+3;
	 }
	 
	}
	


int main()
{
  int n;
  cin>>n;
  int N=pow(2,n);
  splidem(n,1,0,0);
  for(int i=0;i<N;i++){
   for(int j=0;j<N;j++){
       cout<<A[i][j]<<" ";}
       cout<<endl;
  }
}


