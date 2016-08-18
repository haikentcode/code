#include<iostream>
#include<cstring>
using namespace std;

class lcsr{

public:
  long long lcs(string x,string y){

    if(x.length()==0 || y.length()==0) return  0;
    if(x[x.length()-1]==y[y.length()-1]){

          return 1+lcs(x.substr(0,x.length()-1),y.substr(0,y.length()-1)) ;
    }
    else return max(lcs(x,y.substr(0,y.length()-1)),lcs(x.substr(0,x.length()-1),y));

  }

};
class lcsd{

public :

long long lcs(string x,string y){

long long m=x.length();
long long n=y.length();

long long l[m+1][n+1];



for(int i=0;i<=m;i++){
   for(int j=0;j<=n;j++){

     if(i==0 || j==0) l[i][j]=0;

      else if(x[i-1]==y[j-1]) l[i][j]=1+l[i-1][j-1];
      else l[i][j]=max(l[i][j-1],l[i-1][j]);

   }



}
return l[m][n];

}

};

int main(){
lcsr a;
lcsd d;
cout<<a.lcs(string("subhu program churata hai"),string("program subhu churata hai"))<<endl;
cout<<d.lcs(string("abcabcaa"),string("acbacba"));

}
