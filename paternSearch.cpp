#include<iostream>
#include<cstring>

  using namespace std;



int patternSearch(string text,string patrn){
    static bool find=false;
      if(!find){
        if(patrn=="")  {find=true;return 1;}
        if(text=="") return patrn=="";

        if('?'==patrn[0]) patternSearch(text.substr(1,text.length()),patrn.substr(1,patrn.length()))||patternSearch(text,patrn.substr(1,patrn.length()));
        if('*'==patrn[0]) patternSearch(text.substr(1,text.length()),patrn)||patternSearch(text,patrn.substr(1,patrn.length()));
        if(text[0]==patrn[0]) patternSearch(text.substr(1,text.length()),patrn.substr(1,patrn.length()));

          }

       if(find==true) return 1; else return 0;
     }


int main(){
string s="helookiloomulo";
string p="el?";
cout<<patternSearch(s,p);

}
