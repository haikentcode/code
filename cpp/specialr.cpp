#include<iostream>
#include<string>

using namespace std;

void hkfun(char *s){

if(*s=='\0') return;
  
string ts;
while(*s!='\0' && *s!=' '){

  ts+=*s;
  s++;
}

if(*s==' ') hkfun(s);

cout<<ts<<" ";

}

int main(){
char s[1000];

cin.getline(s,1000);
cout<<s;

hkfun(s);


}
