#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
/* Head ends here */


long long int stringSimilarity(char a[]) {

      int n=strlen(a);
      int total=n;
      queue<int> q;
      
     for(int i=1;i<n;i++){
          if(a[i]==a[0])q.push(i);
       }                        
     
     int j=1;
    while(!q.empty()){
     
        queue<int> tm;
        while(!q.empty()){
            int t=q.front();
             if(t+1<n){
                 if(a[t+1]==a[j]){
                     tm.push(t+1);
                     total+=1;
                 }
             }
        }
        j++;
       q=tm;
    }

   return total;
}
int main() {
    int t, i;
    scanf("%d",&t);
    char a[100001];
    for (i=0;i<t;i++) {
        scanf("%s",a);
        long long int res=stringSimilarity(a);
        printf("%lld\n",res);  
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

