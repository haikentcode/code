#include<iostream>
#include<cstring>
using namespace std;

int main(){
 string hand[]={"thumb","Index","Middle","Ring","Little"};
 int n;
 cin>>n;
  if(n<=0) return 0;
  if(n>5){
       
      n=n-5;
      
      int i=n/4;
      int k=n%4;
      if(i%2==0){
                
                cout<<hand[4-k];

             }else{
                    cout<<hand[k];
                 }

   }else
   {
      cout<<hand[n-1];
   } 

}
