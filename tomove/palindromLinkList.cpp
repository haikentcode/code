#include<iostream>
using namespace std;

struct node{
	node *link;
	int data;
};


class LinkList{
	node *head;
	node *tail;

	public:
		LinkList(){
			 head=NULL;tail=NULL;
		}

		node *getHead(){
			return head;
		}
		void setHead(node *nhead){
			head = nhead;
		}

		void add(int data){
			node *tm;
			tm = new node;
			tm->data = data;
		  if(tail==NULL){
				 head = tm;
				 tail = tm;
			}else{
         tail->link = tm;
				 tail=tm;
			}
		}

		void printList(){
			node *tm;
			tm = getHead();
			while(tm){
				cout<<tm->data<<'\n';
				tm = tm->link;
			}
		}

};

bool isPalindrom(node *head){
   node *fp;
	 node *sp;
	 fp = head;
	 sp = head;
	 while(fp && fp->link){
		 sp = sp->link;
		 if(fp->link){
			 fp = fp->link->link;
		 }else{
			 fp = fp->link;
		 }
	 }

	 node *mid;
	 node *start;
	 mid = sp;
	 start = head;


	 while(mid){
		 cout<<start->data<<" "<<mid->data<< '\n';
		 if(start->data == mid->data){
			 start = start->link;
		   mid = mid->link;
		 }else{
			 return false;
		 }
	 }

	 return true;

}

node * reverse(node * head){
	if(head ==  NULL){
		return head;
	}
	node *pre,*curr;
	curr = head;
	pre = NULL;
	while(curr->link){
		 node *tm;
	   tm = curr->link;
		 curr->link = pre;
		 pre = curr;
		 curr = tm;
	}
  if(curr->link == NULL){
		curr->link = pre;
	}
	return curr;
}

int main(){
  LinkList list;
	list.add(4);
	list.add(6);
	list.add(7);
	list.add(9);
	list.printList();
	node *newHead = reverse(list.getHead());
	list.setHead(newHead);
	cout<<"\n---------------\n";
	list.printList();

}

// a -(^)> b -(^)> c -(^)> d -(^)> null
// a->next = null ^ b
// b->next = a ^ c
// c->next = b ^ d
// d-> next = c ^ null;
