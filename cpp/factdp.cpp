#include<iostream>
#include<cstdlib>
using namespace std;
int fac[1000];

int factdp(int n){
  if(n==0) return 1;
  else if(n==1) return 1;
  else if(fac[n]!=0) return fac[n];
  else return fac[n]=n*factdp(n-1);

}
int fact(int n){
   if(n==1) return 1;
   else return n*fact(n-1);
   }


int main(int argc,char *argv[]){

if(argc>=2){
for(int i=1;i<argc;i++)
{
 int n=atoi(argv[i]);
 cout<<factdp(n)<<endl;

}

}

}


