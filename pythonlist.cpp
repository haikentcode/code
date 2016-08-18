#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

template<class var>
class Node{
  public:
    var data;
    Node<var> next=new Node<var>;
    Node<var> pre=new Node<var>;
    Node(var d){
       data=d;
       next=NULL;
       pre=NULL;
   }  
}

int main(){
  Node<string> nd=new Node<string>;
  nd.data="how to feel now";
   
   cout<<nd.data<<endl;
}
