#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
int main(int argc,char *argv[]){
 char cmd[1000],in[100],out[100];

  if(argc>1){
    cout<<"or kya chal rio hai \n";
    sprintf(in,"%s.cpp",argv[1]);
    sprintf(out,"/home/hitesh/Desktop/code/lbin/%s",argv[1]);
    sprintf(cmd,"g++ %s -o %s",in,out);
    system(cmd);
    cout<<"ho gayo taro kaam \n";
    }
  else{
    cout<<"haikent is awesome but your command not";
    }

}
