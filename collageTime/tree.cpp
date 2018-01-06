#include<iostream>
#include<queue>
#include<stack>
#include<map>
using namespace std;

template<class t>
struct node{
t data;
node *left;
node *right;
};


template<class t>
class tree{
node<t> *head;

public:
    tree(){
      head=NULL;
      }

node<t> *Node(t data){
 node<t> *p;
 p=new node<t>;
 p->data=data;
 p->left=NULL;
 p->right=NULL;
 
}

  void insert(t data){

       if(head==NULL){
           head=Node(data);
       }

       else{
           
	   rec(head,Node(data));
        

       }

  }

  void rec(node<t> *r,node<t> *nd){
      
       
       if(r->data>nd->data){
            if(r->right) rec(r->right,nd);
	       else r->right=nd;

       }else{
         if(r->left) rec(r->left,nd);
	  else r->left=nd;
       }


  }

  void traverse(){
         
	 order(head);

  }

 void order(node<t> *hrad){
     
     queue<node<t> *> Q;
      
      if(!head) return;
      Q.push(head);


      while(!Q.empty()){
          
	  node<t> *p=Q.front();
	  Q.pop();
          cout<<p->data<<" ";
	  if(p->left) Q.push(p->left);
	  if(p->right) Q.push(p->right);

      }

 }
 node<t> *getHead(){ return head;}

 int height(node<t> *r){
     
      if(r==NULL)  return 0;
      else return (max(height(r->left),height(r->right))+1);

 }
 
  int Diameter(){
     int a=0;
      
       diameter(head,&a);
       return a;
      
  }


  int diameter(node<t> *nd,int *ptr){
       
       if(nd==NULL) return 0;
       int left=diameter(nd->left,ptr);
       int right=diameter(nd->right,ptr);

       if(left+right>*ptr) *ptr=left+right;

       return max(left,right)+1;

  }

  void verticaltrav(node<t> *nd,int column){

     if(nd==NULL)return;
     
     verticaltrav(nd->left,column+1);
     verticaltrav(nd->right,column-1);
     cout<<"("<<nd->data<<","<<column<<")"<<endl;    

}


  void bordertrav(node<t> *nd)
   {
    
     if(nd==NULL) return;
     static bool hk=true;
      
      if(hk){
              node<t> *tm;
              cout<<nd->data<<" ";
              tm=nd->left;
              while(tm) { if(tm->left!=NULL) cout<<tm->data<<" "; tm=tm->left; }
              tm=nd->right;
              while(tm){ if(tm->right!=NULL) cout<<tm->data<<" "; tm=tm->right;}
             hk=false;
            }

        bordertrav(nd->left);
        bordertrav(nd->right);
        if(nd->left==NULL & nd->right==NULL) cout<<nd->data<<" ";
  }
   
 void zigzagtrav(){
  
 node<t> *nd=head;
 if(!nd) return;
  
   stack<node<t> *> s1,s2;
  bool hios=true;
  s1.push(nd);
  while(!s1.empty()){

      nd=s1.top(); s1.pop();
      if(nd){
               cout<<nd->data<<" ";
               if(hios){
                         if(nd->left) s2.push(nd->left);
                         if(nd->right)s2.push(nd->right);
                       }
                else  {
                         if(nd->right) s2.push(nd->right);
                         if(nd->left) s2.push(nd->left);
                      }

            }
           if(s1.empty()){
                      hios=!hios;
                      swap(s1,s2);
                  }

   }


}


void verticalsum(){

 map<int,int> hash;
 stack<pair<node<t> *,int> > s;
 
 if(head==NULL) return;
 node<t> *tm; 
 tm=head;
 int clm=0; 
 while(1){

      while(tm){
             s.push(pair<node<t> *,int>(tm,clm));
             clm--;
             tm=tm->left;
            }
         if(s.empty()) break;

       pair<node<t> *,int> p=s.top();s.pop();
       tm=p.first;
       clm=p.second;
       hash[clm]+=tm->data;
       tm=tm->right;clm++;

  }
  map<int,int>::iterator it;
  cout<<"verticalsum=";
  for(it=hash.begin();it!=hash.end();++it) cout<<it->second<<" ";

}


};


int main(){
tree<int>  t;
int n;
cin>>n;
for(int i=0;i<n;i++) {int x;cin>>x;t.insert(x);}

t.traverse();
cout<<endl;
cout<<"height="<<t.height(t.getHead())<<endl;
cout<<"diameter="<<t.Diameter()<<endl;
t.verticaltrav(t.getHead(),0);
cout<<endl;
t.bordertrav(t.getHead());
cout<<endl;
t.zigzagtrav();
cout<<endl;
t.verticalsum();
}
