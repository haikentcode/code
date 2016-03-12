#include<iostream>
#define PL cout<<endl;
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define output(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";
using namespace std;


void insertionsort(int a[],int n){

    for(int i=2;i<n;i++){
      
         int j=i;
         int v=a[i];
          while(a[j-1]>v && j>=1){
                a[j]=a[j-1];
                j--;
            }

        a[j]=v;
   }

}



int main(){

   int n;
   cin>>n;
   int a[n];
   input(a,n);
   output(a,n); PL
   insertionsort(a,n);
   output(a,n);



}
