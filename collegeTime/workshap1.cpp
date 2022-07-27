#include<iostream>
#include<cstdlib>
#define hkint int64_t
#define HKCONS 505
#define loop(n,x) for(int x=1;x<=n;x++)
using namespace std;
class snakGame{
            hkint dp[HKCONS][HKCONS];
            hkint up[HKCONS];
            hkint down[HKCONS];
            hkint box[HKCONS][HKCONS];
            int n;
            int m;

            public:
                 snakGame(int nn,int mm){
                   n=nn;
                   m=mm;
                 }

                 void input(){
                        loop(n,i)
                           loop(m,j)
                                cin>>box[i][j];
                 }


                hkint maxFood(){

                       loop(m,j)
                               {
                                   loop(n,i)
                                         {
                                           down[i]=max(dp[i][j-1],down[i-1]);
                                           down[i]=(box[i][j]==-1||down[i]==-1)?-1 :down[i]+box[i][j];
                                           if(i==1&&box[n][j]!=-1)
                                              down[i]=max(down[i],box[i][j]);
                                         }

                                        for(int i=n;i>=1;i--)
                                                {
                                                    up[i]=max(dp[i][j-1],up[i+1]);
                                                    up[i]=(box[i][j]==-1||up[i]==-1)?-1:up[i]+box[i][j];
                                                    if(i==n&&box[1][j]!=-1)
                                                      up[i]=max(up[i],box[i][j]);
                                              }
                                         loop(n,i)
                                         {
                                             dp[i][j]=max(up[i],down[i]);
                                         }
                                  }

                                    hkint ans=-1;
                                    loop(n,i)ans=max(ans,dp[i][m]);
                                       return ans;

                                }
};



int main()
 {
     int64_t n,m,i,j;
     cin>>n>>m;
     snakGame game(n,m);
     game.input();
     cout<<game.maxFood();

 }
