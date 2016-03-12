#include<iostream>
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i]
#define output(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";
#define PL cout<<endl;
using namespace std;

void selectionsort(int a[],int n){
   
        
    for(int i=0;i<n-1;i++){
        
       int min=i;
       for(int j=i+1;j<n;j++){
           
                if(a[min]>a[j]) min=j;
          }  

       swap(a[i],a[min]);
     }

}

int main(){

    int n;
    cin>>n;
    int a[n];
    input(a,n);
    output(a,n); PL
    selectionsort(a,n);
    output(a,n);


}
