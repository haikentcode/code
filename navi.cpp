#include<bits/stdc++.h>
using namespace std;

int main()
 {
  string s="'{1,7,5,2},{5,12,3,6},{100,9,23,16},{16,4,5,9}'";
  getline(cin,s);
  int n;
  cin>>n;
  int a[n+1][n+1],dp[n+1][n+1];
  memset(dp,0,sizeof(dp));
  int b[n*n];
  int i=0,l=0;
  while(i<s.length())
   {
      if(s[i]<=57 && s[i]>=48)
       {
         int x;
         x=s[i]-48;
         i++;
         while(s[i]<=57&&s[i]>=48)
          {
            x=x*10 + s[i]-48;
            i++;
          }
          b[l++]=x;
       }
       else i++;
   }
   for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
       {
         a[i+1][j+1]=b[i*n+j];
         cout<<a[i+1][j+1]<<" ";
       }
       cout<<"\n";
    }
   for(int i=1;i<=n;i++)
    {
     for(int j=1;j<=n;j++)
       {
         dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
       }
    }
    cout<<dp[n][n]<<"\n";

 }
