#include<iostream>
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i]
#define  output(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" "
#define PL cout<<endl; 
using namespace std;


int pivot(int a[],int b[],int l,int r){
  
  cout<<l<<" "<<r<<endl;
  int i=l,j=r;
  int p=b[l];

   while(i<j){
 
         while(a[b[i]]<=a[p])i++;
         while(a[b[j]]>a[p])j--;

         if(i<j)
           {
                 
             int tm=b[i];
             b[i]=b[j];
             b[j]=tm;

           }
     }

   
  b[l]=b[j];
  b[j]=p;
   
  return j;
}

void rec(int a[],int b[],int l,int r){
   
   if(l<r){
    
     int p=pivot(a,b,l,r);
     rec(a,b,l,p-1);
     rec(a,b,p+1,r);

   }


}

void quicker(int a[],int b[],int n){

     
       rec(a,b,0,n-1);            
   
}


int main(){

  int n;
  cin>>n;
  int a[n],b[n+1];
  for(int i=0;i<n+1;i++)b[i]=i;
   input(a,n);
   output(a,n);
   PL
   quicker(a,b,n);
   for(int i=0;i<n;i++) cout<<a[b[i]]<<" ";
   PL
}


