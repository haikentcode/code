#include<iostream>
using namespace std;
#define input(a,n) for(int i=0;i<n;i++)  cin>>a[i]
#define output(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" "
#define PL cout<<endl;
#define HK true
#define DEBUG if(HK){\
                 cout<<__LINE__;\
                 }\

#define haiku(function)   int n;\
                          cin>>n;\
                          int a[n];\
                          input(a,n);\
                          output(a,n);PL\
                          function(a,n);\
                          output(a,n);PL\
                

void bucketsort(int a[],int n){
  DEBUG
  int bs=100000;
  for(int i=0;i<n;i++) if(a[i]>bs) bs=a[i];
  DEBUG
   int B[++bs];
    DEBUG
   for(int i=0;i<n;i++) B[i]=0;
   DEBUG
   for(int i=0;i<n;i++) B[a[i]]+=1;
   DEBUG

  for(int i=0,j=0;i<bs;i++){
         DEBUG   
            int k=B[i];
            while(k>0) a[j++]=i;
   }  



}

int main(){
  
  haiku(bucketsort)   

}
