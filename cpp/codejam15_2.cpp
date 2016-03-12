#include<iostream>
using namespace std;

int main(){


long long t;
cin>>t;

while(t--){

    long long  a[10000+1]={0};

    long long n;
    cin>>n;
    int mmax=0;
    for(int i=0;i<n;i++){
       long long tm;
       cin>>tm;
       a[tm]+=1;
       if(tm>mmax)mmax=tm;
    }


   int ttime=0;

   for(int i=10000;i>=0;)
   {

      if(a[i]!=0)
      {



          long long int p1=a[i]/2;
          long long int p2=a[i]-p1;

          if((ttime+1+max(p1,p2))<a[i]+ttime)
          {

            a[p1]+=1;
            a[p2]+=1;
            ttime++;

            if(a[i]!=0) a[i]-=1; else i--;

          }
          else
          {
              ttime+=i;
              break;
          }



      }else
         {
          i--;
         }


   }

   cout<<"#->"<<ttime<<endl;


}


}
