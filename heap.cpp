#include<iostream>
using namespace std;

class heap{
int *A;
int count;
int size;
public:
  heap(int s=1){
     size=s;
     A=new int[size];
     count=0;
     }

  int Left(int i)
            { 
	     int left=2*i+1;
	     if(left>=count) return -1; 
	     else return left;
	     }
  int Right(int i)
             {
	      int right=2*i+2;
	      if(right>=count) return -1; 
	      else return right;
	      }

  void insert(int data){
      if(count==size) resize();
      count++;
      int i=count-1;
      while(i>=1 && data>A[(i-1)/2]){
         A[i]=A[(i-1)/2];
	 i=(i-1)/2;
	 }
	 A[i]=data;
     }
 
 void resize(){
    int oldsize=size;
    int *oldA=A;
    A=new int[size*2];
    size*=2;
    for(int i=0;i<count;i++)A[i]=oldA[i];
    delete[] oldA;
    }

void heapifying(int i){
      int l=Left(i);
      int r=Right(i);
      int max=0;

      if(l!=-1 && A[l]>A[i]) max=l; else max=i;
      if(r!=-1 && A[r]>A[max]) max=r;
      if(max!=i){
          int tmp=A[i];
	  A[i]=A[max];
	  A[max]=tmp;
	  heapifying(max);
	  }
}

int getMax(){
 
 if(count==0) return -1;
 else return A[0];

}

int kthsmallest(int i,int *k,int kth){
 

}


};

int main(){
heap h;

   do{
       cout<<"1: Insert\n";
       cout<<"2: getMax\n";
       cout<<"3: kthsmallest\n";
       int c;
       cin>>c;
       if(c==1){ 
                    int n;
		    cin>>n;
		    h.insert(n);
		}
        else if(c==2){
	               cout<<endl<<h.getMax();}


            
        else if(c==3){
	               int k=0;
		       int kth;
		       cin>>kth;
	               cout<<endl<<h.kthsmallest(0,&k,kth);
		       }
	       


         }while(1);


}
