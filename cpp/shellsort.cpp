#include<iostream>
using namespace std;

void shellsort(int A[],int asize){
int h,v,j;
for(h=1;h<=asize/9;h=h*3+1);

for(;h>0;h=h/3){
  for(int i=h+1;i<asize;i+=1){
      v=A[i];
      j=i;
      while(j>h&&A[j-h]>v){
          A[j]=A[j-h];
          j=j-h;
      }
      A[j]=v;
  }

}



}

int main(){
int n;
cin>>n;
int A[n];
for(int i=0;i<n;i++) cin>>A[i];
shellsort(A,n);
for(int i=0;i<n;i++) cout<<A[i]<<" ";
}
