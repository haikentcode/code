#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int x,y;
x=0;
y=0;

void *Run1(void *arg){

  while(!x);

  printf("hello I am waiting thread");


}

void *Run2(void *arg){

printf("enter value of x for start p1");
scanf("%d",&x);

}


int main(){
pthread_t readt,writet;
int rc,t;
t=0;
rc=pthread_create(&readt,NULL,Run1,(void *)t);
t++;
if(rc) {printf("ERROR ->%d",rc);exit(-1);}

rc=pthread_create(&writet,NULL,Run2,(void *)t);

if(rc){printf("Error->%d",rc);exit(-1);}


pthread_exit(NULL);

}

