#include<iostream>
#include<string>
using namespace std;

template<class haiku>
struct nod{
	haiku data;nod *next;
};

template<class haiku>
class list{
	nod<haiku> *head;
	nod<haiku> *tell;

	public:
    list(){
			 head=NULL;tell=NULL;
    }

		nod<haiku> *getHead(){
			return head;
		}

    void add(haiku data){
        nod<haiku> *tm;
        tm=new nod<haiku>;
        tm->data=data;tm->next=NULL;
				if(tell==NULL) {
					head=tm;tell=tm;
				}else{
					tell->next=tm;
        	tell=tm;
        }
      }

		void delt(haiku k){
			  if(head!=NULL){
					nod<haiku> *tm=head;
					if(tm->data==k){
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
     while(tm!=NULL){
			 dout<<tm->data<<","; tm=tm->next;
		 }
     dout<<"]";
     return dout;
   }

};

int main(){
 list<string> l;
 int n;
 cin>>n;
 for(int i=0;i<n;i++) cin>>l;
 cout<<l;
 cout<<endl;
}
