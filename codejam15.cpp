#include<iostream>
#include<string>
#include<unistd.h>
using namespace std;

int toInt(char c){

return c-'0';

}

int hios(int smax,string s){

  long long int person=0;
  long long int invitep=0;
  for(int i=0;i<=smax;i++){

  	if(i==0){person+=toInt(s[i]);}
  	 else if(toInt(s[i])!=0)
  	 {

  	 	if(person<i){

            invitep+=i-person;
  	 		person=person+toInt(s[i])+i-person;

  	 	}
  	 	else{

           person+=toInt(s[i]);

  	 	}
  	 }

  }


  return invitep;


}

int main(){

   long long int t;
   cin>>t;
   long long i=1;
   while(t--){

     long long int smax;
     string si_string;
     cin>>smax;
     cin>>si_string;

   	 cout<<"Case #"<<i++<<": "<<hios(smax,si_string)<<endl;



   }


}
