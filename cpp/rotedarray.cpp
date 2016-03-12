#include<iostream>
using namespace std;

int bs(int A[],int left,int right,int k){

      int mid=left+(right-left)/2;
      if(left<=right){
      if(A[mid]==k) return mid;
      else if(A[mid]>k) return bs(A,left,mid-1,k);
      else return bs(A,mid+1,right,k);}
  return -1;
}



int brs(int A[],int left,int right,int k){

 int mid=left+(right-left)/2;
 
 if(left<=right){
   
    if(A[mid]==k) return mid;
    
    else if(A[mid]>k){
           
      if(A[left]<=k) return brs(A,left,mid-1,k);
      else return brs(A,mid+1,right,k);      

    } 
    else{

         
      if(A[right]>=k) return brs(A,mid+1,right,k);
     else return brs(A,left,mid-1,k); 

   }
  
  }

return -1;
}
int search(int A[],int n,int k){

return brs(A,0,n,k);

}
int main(){

int n;
cin>>n;
int A[n];
for(int i=0;i<n;i++) cin>>A[i];

for(int i=0;i<n;i++) cout<<A[i]<<" ";

while(1){

int k;
cin>>k;
cout<<search(A,n,k);

}

}
