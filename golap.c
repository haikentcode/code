#include <stdlib.h>
#include <stdio.h>

struct pair{
      int x,y;
};
struct QNode
{
    struct pair key;
    struct QNode *next;
};

struct Queue
{
    struct QNode *front, *rear;
};

struct QNode* newNode(struct pair k)
{
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue *q, struct pair k)
{

    struct QNode *temp = newNode(k);
    if (q->rear == NULL)
    {
       q->front = q->rear = temp;
       return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct QNode *deQueue(struct Queue *q)
{

    if (q->front == NULL)
       return NULL;
    struct QNode *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
       q->rear = NULL;
    return temp;
}

int main()
{

  int T;
  scanf("%d",&T);

  while(T--){

     struct Queue *q = createQueue();

     int n,m,i,j;
     scanf("%d%d",&n,&m);
     char mtrx[n][m];

     struct pair start;

     for(i=0;i<n;i++){
       scanf("%s",&mtrx[i]);
     }

     int trav[n][m];

     for(i=0;i<n;i++){
        for(j=0;j<m;j++){

          if(mtrx[i][j]=='S'){

             start.x=i;
             start.y=j;
             trav[i][j]=0;
          }

          trav[i][j]=-1;

        }
    }



     struct QNode *nd=newNode(start);

     enQueue(q,start);
     struct pair tm;
     int maxp=-1;

     while(nd!=NULL){

       nd=deQueue(q);
       if(nd==NULL) continue;
       tm=nd->key;
       int pc=trav[tm.x][tm.y];
       printf("pc->%d\n",pc);

       //up
       if(tm.y-1>=0){

           struct pair tmp={tm.x,tm.y-1};

           if(trav[tmp.x][tmp.y]==-1){

           if(mtrx[tm.x][tm.y - 1 ]== '~')
           {
               trav[tmp.x][tmp.y]=pc+1;
               maxp=pc+1;
               break;
           }

           if(mtrx[tm.x][tm.y - 1 ]== '-'){
              trav[tmp.x][tmp.y]=pc+1;
              enQueue(q,tmp);
           }

          }

       }

       //down
       if(tm.y + 1< n){

         struct pair tmp={tm.x,tm.y+1};
         if(trav[tmp.x][tmp.y]==-1){

             if(mtrx[tm.x][tm.y +1 ]== '~')
           {

              trav[tmp.x][tmp.y]=pc+1;
               maxp=pc+1;
               break;
           }

           if(mtrx[tm.x][tm.y + 1 ]== '-'){
              trav[tmp.x][tmp.y]=pc+1;
              enQueue(q,tmp);
           }
        }

       }

       //left
       if(tm.x+1<m){

        struct pair tmp={tm.x+1,tm.y};
      if(trav[tmp.x][tmp.y]==-1){
        if(mtrx[tm.x+1][tm.y]== '~')
           {
              trav[tmp.x][tmp.y]=pc+1;
               maxp=pc+1;
               break;
           }

          if(mtrx[tm.x+1][tm.y]== '-'){
              trav[tmp.x][tmp.y]=pc+1;
              enQueue(q,tmp);
           }

       }

       }


       //right
       if(tm.x-1>=0){

         struct pair tmp={tm.x+1,tm.y};
           if(trav[tmp.x][tmp.y]==-1){
         if(mtrx[tm.x-1][tm.y]== '~')
           {
              trav[tmp.x][tmp.y]=pc+1;
               maxp=pc+1;
               break;
           }


        if(mtrx[tm.x-1][tm.y ]== '-'){
              trav[tmp.x][tmp.y]=pc+1;
              enQueue(q,tmp);
           }

       }

       }


     }

      printf("%d\n",maxp);


  }



}
