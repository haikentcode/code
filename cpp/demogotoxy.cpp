#include<iostream>
#include<stdio.h>
using namespace std;
void gotoxy(int x,int y){
printf("\033[%d;%df",x,y);
fflush(stdout);
}

int main(){

gotoxy(10,20); cout<<"aditi";
gotoxy(20,10); cout<<"hitesh";

}
