#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
bool __UNDIRECTED__=true;
using namespace std;


struct graph{

int v;
int e;
int **Adj;
};

class Graph{

graph G;
int E,V;
int *visited;
int *indegree;
int *topologicalorder;
public:
 Graph(int v,int e){
    G.e=e;
    G.v=v;

     G.Adj= new int *[v];
     for( int i = 0 ; i <v ; i++ )
          G.Adj[i]= new int[v];
    visited=new int [v];
    indegree=new int [v];
    topologicalorder=new int[v];

   for(int i=0;i<v;i++){visited[i]=0;    topologicalorder[i]=0;}
   for(int i=0;i<v;i++){for(int j=0;j<v;j++){G.Adj[i][j]=0;}}

 }

 ~Graph(){
 for( int i = 0 ; i < G.v ; i++ ) delete [] G.Adj[i] ;
 delete [] visited;
 delete [] indegree;
 delete [] G.Adj;
 delete [] topologicalorder;

 }

 void Edge(int u,int v,int w=1){
  G.Adj[u][v]=w;
 if(__UNDIRECTED__)  G.Adj[v][u]=w; /*undirected graph */
 }

 int isConnect(int u,int v){

 return G.Adj[u][v];
 }

 void DFS(){

        for(int i=0;i<G.v;i++){visited[i]=0;}
        for(int i=0;i<G.v;i++){

          if(!visited[i]){
           dfs(i);
          }

        }
 }

 void dfs(int v){
 cout<<v<<" ";
 visited[v]=1;

  for(int i=0;i<G.v;i++){

   if(!visited[i]&&G.Adj[v][i]){
   dfs(i);
   }

  }

 }

void BFS(){

for(int i=0;i<G.v;i++){visited[i]=0;}
        for(int i=0;i<G.v;i++){

          if(!visited[i]){
           bfs(i);
          }

        }


}

void bfs(int u){

   queue<int > Q;

   Q.push(u);

  while(!Q.empty()){
   u=Q.front();
   Q.pop();
   if(!visited[u])cout<<u<<" ";
   visited[u]=1;

   for(int i=0;i<G.v;i++){

    if(!visited[i]&&G.Adj[u][i]){
      Q.push(i);
    }
   }

  }
}


void computeIndegree(){


for(int j=0;j<G.v;j++){
int counter=0;
for(int i=0;i<G.v;i++){
 if(G.Adj[i][j])counter++;
}
 indegree[j]=counter;
}

}

int Degree(int u){computeIndegree();return indegree[u];}


void Topologicalsort(){
computeIndegree();
queue<int> Q;
int counter=0;
for(int i=0;i<G.v;i++){

 if(indegree[i]==0){
  Q.push(i);

 }

}

while(!Q.empty()){
int u=Q.front();
Q.pop();
topologicalorder[u]=++counter;

for(int i=0;i<G.v;i++){

 if(G.Adj[u][i]){

  if(--indegree[i]==0){

    Q.push(i);
  }

 }

}


}

if(counter!=G.v){
cout<<"\ngraph has cycle\n";
} else
{
cout<<"\n";
int sortlist[G.v];
for(int i=0;i<G.v;i++){

sortlist[topologicalorder[i]-1]=i;
}

for(int i=0;i<G.v;i++){
cout<<sortlist[i]<<" ";
}

}

}


int topologicalorderIs(int u){

Topologicalsort();

return topologicalorder[u];
}




void shortPath(int s){

int path[G.v];
int Distance[G.v];
for(int i=0;i<G.v;i++){
path[i]=0;
Distance[i]=-1;
}
Distance[s]=0;

queue<int> Q;
Q.push(s);

while(!Q.empty()){
  int v=Q.front();Q.pop();
for(int i=0;i<G.v;i++){

 if(G.Adj[v][i]){

  if(Distance[i]==-1){
  Distance[i]=Distance[v]+1;
  path[i]=v;
  Q.push(i);
  }

 }

}
}

cout<<"\n shortes path from:"<<s<<"\n";
for(int i=0;i<G.v;i++){

cout<<i<<":"<<"d="<<Distance[i]<<" prev="<<path[i]<<"\t";

}

}


void wshortPath(int s){


}


};

int main(){

Graph G(6,8);
__UNDIRECTED__=false;
G.Edge(0,1);
G.Edge(0,2);
G.Edge(0,3);
G.Edge(1,3);
G.Edge(1,4);
G.Edge(2,3);
G.Edge(3,5);
G.Edge(4,5);
G.DFS();
cout<<endl;
G.BFS();
G.Topologicalsort();

cout<<endl<<"G2"<<endl;
Graph G2(10,9);
G2.Edge(0,8);
G2.Edge(0,9);
G2.Edge(0,1);
G2.Edge(2,9);
G2.Edge(2,7);
G2.Edge(7,8);
G2.Edge(4,0);
G2.Edge(6,0);
G2.Edge(6,7);
G2.Topologicalsort();


G2.shortPath(6);





}
