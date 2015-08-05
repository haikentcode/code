#include<iostream>
#include<string>

using namespace std;

template<class haiku>
struct node{
 
 haiku data;
 node *left;
 node *right;

};

template<class haiku>
struct nod
{
	haiku data;
	nod *next;

};

template<class haiku>
class list{

	nod<haiku> *head;
	nod<haiku> *tell;
    
    public:
    	 list(){

    	 	head='\0';
    	 	tell='\0';
    	 }
           
        nod<haiku> *getHead(){return head;}
        
        void add(haiku data){
            
             nod<haiku> *tm; 
             tm=new nod<haiku>;
             tm->data=data;tm->next='\0';
             
        	if(tell=='\0') {head=tm;tell=tm;}

        	else{

        		tell->next=tm;
        		tell=tm;
        	}
        }


       void delt(haiku k){
                     
                  if(head!='\0'){
                      
                        nod<haiku> *tm=head;
                        
                         if(tm->data==k)
                         {
                            
                            head=tm->next;
                           
                         }

                         while(tm->next && tm->next->data!=k){
                         	
                         	  tm=tm->next;
                         }

                         tm=tm->next->next;

                  }  
       }  


       


    friend istream & operator >> (istream &din,list<haiku> &l){
     
            haiku dt;
            din>>dt;        
            l.add(dt);  
            return(din);          
    }
   
   friend ostream & operator <<(ostream &dout,list<haiku> &l){
 
     haiku dt;
     
     nod<haiku> *tm;

     tm=l.getHead();
     dout<<"[ ";
     while(tm!='\0') {dout<<tm->data<<" "; tm=tm->next;}

     dout<<"]";	
       

     return dout;

   }


};




template<class haiku>
class stack{

   nod<haiku> *top;
   
   public:
     
     void push(haiku d) {
          
           nod<haiku> *tm; 
           tm=new nod<haiku>;
           tm->data=d;tm->next='\0';

          if(top=='\0'){
             top=tm;
          }else{
             
             tm->next=top;
             top=tm;

          }
     } 
   
   haiku pop(){
          
          haiku tm; 
          
         if(top=='\0'){return tm;}
         else
         {
         	 tm=top->data;
         	 top=top->next;
         	 return tm;
         }

        

   }
 

    void operator =(haiku k)
    {
    	push(k);
    }    
    
   

   friend void  operator <<(haiku &k, stack<haiku> s){
    
    k=s.pop();


   }

   friend ostream & operator <<(ostream &dout,stack<haiku> s){
    dout<<s.pop();
    return dout;
   }

   bool isempty(){
       
       if(top=='\0') return true;
       else return false;

   }



};




template<class haiku>
class Queue
{

 nod<haiku> *top;
 nod<haiku> *tell; 

public:
  Queue(){
    top='\0';
    tell='\0';
     }

   void enq(haiku k){
      
      nod<haiku> *tm; 
      tm=new nod<haiku>;
      tm->data=k;
      tm->next='\0';

     if(top=='\0'){
         
         top=tm;
         tell=tm;
     }else{

        top->next=tm;
        top=tm;

     }


   }

   haiku deq(){
       
       haiku data;
       if(tell!='\0'){
          
          nod<haiku> *rd;
          rd=tell;
          tell=tell->next;  
          data=rd->data;

       }else{ cout<"Q is empty ";}
         
      return data;


   }

  bool isempty()
  {

    if(top=='\0' || tell=='\0') return true;
     else return false;

  }



  ~Queue()
  {


  }

};






template<class haiku>
class btree{
	
  node<haiku> *head;

  public:

        btree(){head='\0';}
        btree(node<haiku> *h){head=h;}  
        node<haiku> *getHead(){return head;}
        
        void insert(haiku data){

              node<haiku> *tm;
              tm=new node<haiku>;
              tm->data=data;
              tm->left='\0';
              tm->right='\0';

               if(head=='\0'){
                  head=tm;
                  cout<<"@";
               }else{

                  
                  Queue<node<haiku> *> q;

                  q.enq(head);

                  while(!q.isempty()){

                        node<haiku> *td=q.deq();
                        
                        if(td->left!='\0') {
                            
                            q.enq(td->left);

                        }else{

                            td->left=tm;
                            cout<<"-";
                            break;

                        }

                       if(td->right!='\0'){
                          
                        q.enq(td->right);

                       }else{
                           
                           td->right=tm;
                           cout<<"#";
                           break;

                       }



                  }


                   

               }




           


        }


        void preordert(){

             rec(head);

        }

        void rec(node<haiku> *r){


          if(r=='\0') return;
             
             cout<<r->data<<" ";
             rec(r->left);
             rec(r->right);
        }

        void levelt(){
                 

             Queue<node<haiku> *> q;
             
             if(head=='\0')return;

             q.enq(head);

             while(!q.isempty()){

                node<haiku> *td=q.deq();
                cout<<td->data<<" ";

                if(td->left!='\0') q.enq(td->left);
                if(td->right!='\0') q.enq(td->right);                   


             }     



        } 



          




};



int main(){
	
 list<string> l;	
  
 int n;
 cin>>n;
 for(int i=0;i<n;i++) cin>>l; 

 cout<<l;

cout<<endl;


 stack<int> s;
 s=3;
 s=4;
 s=6;
 s=7;
stack<int> st;

int k;
k<<s;
  
cout<<s;

Queue<string> q;
q.enq("i love you aditi");
q.enq("my jaan aditi");
q.enq("miss you baby");


while(!q.isempty())
{
  cout<<q.deq()<<endl;
}

btree<int> bt;

bt.insert(1);
bt.insert(2);
bt.insert(3);

bt.levelt();
cout<<"\n";
bt.preordert();

}