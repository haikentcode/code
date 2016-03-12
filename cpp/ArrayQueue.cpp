/*
@HIOS(by haikent)
*/

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

template<class data>
struct Queue{
int front,rear;
int capacity;
data *Array;
};

template<class data>
class ArrayQueue{

Queue<data> Q;

public:
 ArrayQueue(int size){
 Q.capacity=size;
 Q.Array=new data[Q.capacity];
 Q.front=-1;
 Q.rear=-1;
 }


 bool empty(){
 return (Q.front==-1);
 }

 bool full(){

 return ((Q.rear+1)%Q.capacity==Q.front);
 }


 void Enqueue(data d){
  if(!full()){

    Q.rear=(Q.rear+1)%Q.capacity;
    Q.Array[Q.rear]=d;

    if(Q.front==-1)Q.front=Q.rear ;//first time insert
  }else{cout<<"\nQueue is full\n";}

}

data Dequeue(){
data d;
if(!empty()){
d=Q.Array[Q.front];
if(Q.front==Q.rear) {
Q.front=-1;
Q.rear=-1;
}
else{
Q.front=(Q.front+1)%Q.capacity;
}

}else{cout<<"\nQueue is empty\n";}

return d;
}

~ArrayQueue(){
delete [] Q.Array;
}

};


template<class data>
class DynamicArrayQueue{

Queue<data> Q;
public:
 DynamicArrayQueue(){

  Q.capacity=1;
  Q.Array=new data[Q.capacity];
  Q.front=-1;
  Q.rear=-1;
 }

bool empty(){
return (Q.front==-1);
}

bool full(){
return ((Q.rear+1)%Q.capacity==Q.front);
}

void Enqueue(data d){

if(full()){
resize();
}

Q.rear=(Q.rear+1)%Q.capacity;
Q.Array[Q.rear]=d;
if(Q.front==-1) Q.front=Q.rear;

}


void resize(){

int size=Q.capacity;
Q.capacity=Q.capacity*2;
data *newa=new data[Q.capacity];

int i=0;
while(i<size){
newa[i]=Q.Array[i];
i++;
}
Q.Array=newa;
if(!Q.Array)cout<<"\nMEMORY ERROR!\n";

if(Q.front>Q.rear){
  for(int i=0;i<Q.front;i++)
      Q.Array[i+size]=Q.Array[i];
      Q.rear=Q.rear+size;
      }
}

data Dequeue(){
data d;
if(empty()){
cout<<"\nQueue is empty !\n";
}else{

d=Q.Array[Q.front];
if(Q.front==Q.rear) {Q.front=-1;Q.rear=-1;}else{
Q.front=(Q.front+1)%Q.capacity;}

}

return d;
}

};


int main(){

DynamicArrayQueue<string> Q;
Q.Enqueue("aditi");
Q.Enqueue("hitesh");
Q.Enqueue("krishna");
Q.Enqueue("aditi");
Q.Enqueue("hitesh");
Q.Enqueue("krishna");


cout<<Q.Dequeue()<<"\n"<<Q.Dequeue()<<"\n"<<Q.Dequeue()<<"\n"<<Q.Dequeue()<<"\n"<<Q.Dequeue()<<"\n"<<Q.Dequeue();

}
