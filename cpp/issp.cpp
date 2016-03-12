#include<iostream>
using namespace std;

class  Railfence{
public:
   Railfence(){
     }

     string encrypt(string s,int rail){

        if(rail==1) return s;
        string R[rail];

        int j=0;
        int k=0;
        for(int i=0;s[i];i++){

         if(k==0){
              R[j]+=s[i];
              j++;
              if(j==rail){ j-=2;k=1;}
              }
              else{
                 R[j]+=s[i];
                 j--;

                 if(j<0){j=1;k=0;}
              }


        }
        string ns;
        for(int i=0;i<rail;i++) ns+=R[i];


          return ns;

     }


};

class Hillcipher{
//assume that key length 3*3=9
public:
 Hillcipher(){}

  string encrypt(string text,string key){




  }

}

int main(){

Railfence r;
cout<<r.encrypt("helloworld",3);

}
