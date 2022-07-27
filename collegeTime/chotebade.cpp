#include<iostream>
#include<vector>
using namespace std;

pair<int ,int> findIJ(vector<int> a){
   
       int last=a.size()-1;  
        int I=last,J=last;
        int ti=last;
        int tj=last;
        int maxd=0;
        last--;
        while(last--){
               
              if(a[last]>a[tj]){
                           
                           I=ti;
                           J=tj;
                           ti=last;
                           tj=last;
                          }
               
               else{
                       
                       if(a[tj]-a[last]>maxd){
                            ti=last;
                            maxd=a[tj]-a[last];
                        }
                   }   
          }

       if(ti!=tj)
                    return make_pair(ti,tj);
       else return make_pair(I,J);

}

#define input(v,n) while(n--) { int k;cin>>k;v.push_back(k);}

int main(){
 
 while(1){
  int n;
   vector<int> v;
   cin>>n;
   input(v,n);
   pair<int,int> IJ;
   IJ=findIJ(v);
   
    cout<<"=>"<<IJ.first<<" "<<IJ.second<<endl; 
}

}
