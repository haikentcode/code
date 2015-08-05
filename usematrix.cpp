#include<iostream>
#include "matrix.h"
using namespace std;

int main(){

     cout<<"hello matrix\n";
     long long m,n;
     cin>>m>>n;
     Matrix<long long> M(m,n);
       
      for(int i=0;i<m;i++)
          for(int j=0;j<n;j++){
               
               cin>>M.data[j+i*m];
            }
       for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){

               cout<<M.data[j+i*m]<<" ";
            }
             cout<<"\n";}
         
           
   

}
