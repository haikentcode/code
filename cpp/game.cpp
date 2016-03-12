#include <iostream>
#include <cstdio>
#include <stack>
#include <map>
#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<string>

using namespace std;

void gotoxy(int x,int y){

printf("\033[%d;%df",y,x);
	fflush(stdout);
}

void drawchar(int x,int y,char ch){

	gotoxy(x,y);
	cout<<ch;
}

void *Road(void *);

class frame{

	int x;
	int y;
	int w;
	int h;

    public:
    	frame(int x,int y,int w,int h){
    		this->x=x;
    		this->y=y;
    		this->w=w;
    		this->h=h;
    	}

    	int getx(){return x;}
    	int gety(){return y;}
    	int getw(){return w;}
    	int geth(){return h;}

    	void drawbox(){

           //top
           for(int i=x;i<(x+w);i++){
           	drawchar(i,y,'.');
           	//bottom
           	drawchar(i,y+h,'.');
           }

           //left
           for(int i=y;i<(y+h);i++){
           	drawchar(x,i,'.');
           	//right
           	drawchar(x+w,i,'.');
           }

    	}

        void moveroad(){

            pthread_t mroad;
            int a=5;
        	int rc=pthread_create(&mroad,NULL,Road,(void *)a);
        	pthread_exit(NULL);


        }




};

int mcarx=0;
int mcary=0;
void *Road(void *f){


int x=5;
int y=5;
int w=50;
int h=50;
int rw=20;

mcarx=x+w/3+rw/2;
mcary=y+h/3;

            //road left
           for(int i=y;i<(y+h);i++){
           	drawchar(x+w/3,i,'.');
           	//road right
           	drawchar(x+w/3+rw,i,'.');
           }

 while(1){

        drawchar(mcarx,mcary,'#');
 }

}

int main(int argc,char *argv[]){

	frame f1(5,5,50,50);
	f1.drawbox();
	f1.moveroad();
}
