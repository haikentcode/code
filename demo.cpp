#include<iostream>
#include<queue>
int & fun(){
  int a=10;
 return a;
}

int f(int &a){

   return a;
}

template<class t>
void hkswap(t &a,t &b){
  t tm=a;
  a=b;
  b=tm;
}

using namespace std;
int main(){
  cout<<"demo test";
  queue<int> Q;
  Q.push(4);
  Q.push(5);
  cout<<Q.front();
     
   fun()=100;
  cout<<fun();
   
   cout<<endl;
  // cout<<f(130);
   char *s1="hitesh";
   char *s2="aditi";
  
   hkswap(s1,s2);
   cout<<s1<<endl<<s2;

     cout<<endl;

    int *p=NULL;
    int &ref=*p;
    cout<<ref; 
}
