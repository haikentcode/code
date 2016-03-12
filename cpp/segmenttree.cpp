#include<iostream>
#include<cstdio>
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i]
using namespace std;

int mid(int a,int b){
  
 return a+(b-a)/2;
}

int mini(int a,int b){

return a>b?b:a;

}
int r(int *st,int a[],int n,int qs,int qe,int index){

   if(qs<0 || qe>n)
      return ~0;
   if(qs==qe)
       return a[qs];

    int m=mid(qs,qe);

    int left=r(st,a,n,qs,m,2*index+1);
    int right=r(st,a,n,m+1,qe,2*index+2);
    st[index]=mini(left,right);
   return st[index];

}

int *rangeMin(int a[],int n){

      int *st;
      st=new int[n];
      
       r(st,a,n,0,n,0);
       
        return st;

}


int main(){

  int n;
  cin>>n;
  int a[n];
  input(a,n);
  
  int *st=rangeMin(a,n);
   
  cout<<"done";  

}
