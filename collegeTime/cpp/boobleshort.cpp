#include<iostream>
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i]
#define output(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" "
#define PL cout<<endl;
using namespace std;

template<class data>
void BoobleShort(data a[],int n){

    for (int i=n-1;i>=0;i--)
            for(int j=0; j<i;j++){

                  if(a[j]>a[j+1])
                       swap(a[j],a[j+1]);
             }

}



int main(int argc,char *argv[]){

   int n;
   cin>>n;
   int A[n];
   input(A,n); PL
   output(A,n); PL
   BoobleShort<int>(A,n);
   output(A,n);
}
