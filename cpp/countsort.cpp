#include<iostream>
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i]
#define output(a,n,s) for(int i=0;i<n;i++) cout<<a[i]<<s
#define PL cout<<endl;
using namespace std;

void countsort(int a[],int n){
     
   int k=a[0];
   for(int i=0;i<n;i++){ if(a[i]>k) k=a[i];}
   k++; 
   int C[k+1];
   
   for(int i=0;i<k;i++) C[i]=0;
   
   for(int i=0;i<n;i++) C[a[i]]+=1;
   
   for(int i=1;i<k;i++) C[i]+=C[i-1];

   int B[n];
   for(int i=n-1;i>=0;i--){ B[C[a[i]]]=a[i]; C[a[i]]-=1;}
   
   for(int i=0;i<n;i++) a[i]=B[i];
}


int  main(){
  
  int n;
  cin>>n;
  int a[n];
  input(a,n);
  output(a,n," "); PL
  countsort(a,n); 
  output(a,n," "); PL

}

