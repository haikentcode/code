#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<iostream>
#include<map>
#include<string>
#define hkwrite(x) write(1,x,strlen(x))
using namespace std;
void error(const char *msg)
{
    perror(msg);
    exit(0);
}
void gotoxy(int x,int y){
printf("\033[%d;%df",y,x);
fflush(stdout);
}

class hkclient{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;

    public:

     hkclient(char ip[],int p){

          portno =p;
          sockfd = socket(AF_INET, SOCK_STREAM, 0);
         if (sockfd < 0) error("ERROR opening socket");
         bzero((char *) &serv_addr, sizeof(serv_addr));
         serv_addr.sin_family = AF_INET;
         serv_addr.sin_addr.s_addr=inet_addr(ip);
         serv_addr.sin_port = htons(portno);

       }

      int hkconnect(){

       if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");
        return sockfd;

      }





};


void *Read(void *sfd){

  int sktfd=*((int*)(&sfd));
        char buffer[256];

        while(1){
                   bzero(buffer,256);
                   int n = read(sktfd,buffer,255);
                   hkwrite(buffer);
               }
pthread_exit(NULL);

}

void *Write(void *sfd){

int sktfd=*((int*)(&sfd));
char buffer[256];
while(1){
          bzero(buffer,256);
          //gotoxy(10,3);
          hkwrite("->Input msg :");
          fgets(buffer,255,stdin);
          int n = write(sktfd,buffer,strlen(buffer));
        }

pthread_exit(NULL);
}

int main(int argc,char *argv[]){

if (argc < 4) {
       fprintf(stderr,"usage %s hostname port username\n", argv[0]);
       exit(0);
    }

int port=atoi(argv[2]);
hkclient client(argv[1],port);

int sfd=client.hkconnect();

int n = write(sfd,argv[3],strlen(argv[3]));
if (n < 0)  error("ERROR writing to socket");

cout<<"thread start";

pthread_t readt,writet;
int rc=pthread_create(&readt,NULL,Read,(void *)sfd);
    rc=pthread_create(&writet,NULL,Write,(void *)sfd);

pthread_exit(NULL);


}
