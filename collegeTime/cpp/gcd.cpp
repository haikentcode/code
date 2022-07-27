#include<iostream>
#include<cstdlib>
using namespace std;

long long gcd(int a,int b){
  
   if(a%b==0) return b;
  
    else return gcd(b,a%b);

}

int main(int argc,char *argv[]){

if(argc<3) return 0;

  int a=atoi(argv[1]);
  int b=atoi(argv[2]);
  cout<<gcd(a,b)<<endl<<endl;
}
