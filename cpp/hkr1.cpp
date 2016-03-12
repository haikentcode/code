#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main() {
     string s;
     cin>>s;
      int l=s.length();

      int clm=floor(sqrt(l));
      int row=ceil(sqrt(l));


      for(int i=0;i<clm+1;i++){
         for(int j=i;j<s.length();j+=clm+1)
          {

            cout<<s[j];

          }
          cout<<" ";
          }


    return 0;
}
