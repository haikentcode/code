#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int main(){

set<int>  x;

for(int i=0;i<10;i++){
    cout<<"enterany no:";    
   int a;
   cin>>a;
   x.insert(a);
}

cout<<"find element ";
int f;
cin>>f;


if(x.find(f)!=x.end()){
cout<<"Not found";
}else
{
  
cout<<x.count(f);
}



}
