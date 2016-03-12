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

map<string,int> userList;
void error(const char *msg)
{
    perror(msg);
    exit(0);
}



class hkserver{
     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;

     public:
          hkserver(int p){

                sockfd = socket(AF_INET, SOCK_STREAM, 0);
                if (sockfd < 0) error("ERROR opening socket");
                bzero((char *) &serv_addr, sizeof(serv_addr));
                portno =p;
                serv_addr.sin_family = AF_INET;
                serv_addr.sin_addr.s_addr = INADDR_ANY;
                serv_addr.sin_port = htons(portno);

          }
        void hkbind(){
        if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) error("ERROR on binding");

        }

        void hklisten(int n=5){
            listen(sockfd,n);
            clilen = sizeof(cli_addr);
        }
        int hkaccept(){

         newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr,&clilen);
         if(newsockfd<0) error("error in accept");
         return newsockfd;
        }


};

void *Gudan(void *sfd){

int skt_fd=*((int*)(&sfd));
char buffer[256];
 while(1){


       bzero(buffer,256);
       int n = read(skt_fd,buffer,255);
       if (n < 0) {error("ERROR reading from socket");}
       if(buffer[0]=='\0')
       {
          hkwrite("client goes offline\n");
          break;
       }
        hkwrite(buffer);
        hkwrite("\n");

      }

     close(skt_fd);

   pthread_exit(NULL);



}


void *Read(void *sfd){

  int sktfd=*((int*)(&sfd));
        char buffer[256];

        while(1){
                   bzero(buffer,256);
                   int n = read(sktfd,buffer,255);
                   write(1,buffer,strlen(buffer));//cout<<buffer;
               }
pthread_exit(NULL);

}

void *Write(void *sfd){

int sktfd=*((int*)(&sfd));
char buffer[256];
while(1){
          bzero(buffer,256);
          hkwrite("\n new msg->");
          fgets(buffer,255,stdin);
          int n = write(sktfd,buffer,strlen(buffer));
        }

pthread_exit(NULL);
}

void *Haiku(void *sktfd){
pthread_t readt,writet;
int sfd=*((int*)(&sktfd));
int rc=pthread_create(&readt,NULL,Read,(void *)sfd);
    rc=pthread_create(&writet,NULL,Write,(void *)sfd);

pthread_exit(NULL);

}


void *Gunjan(void *sfd){


int skt_fd=*((int*)(&sfd));
char buffer[256];

       bzero(buffer,256);
       int n = read(skt_fd,buffer,255);
       if (n < 0) {error("ERROR reading from socket");}
       write(1,buffer,strlen(buffer));
       string userName=string(buffer);
       userList[userName]=skt_fd;
       hkwrite("new user is:");hkwrite(buffer);

 while(1){


       bzero(buffer,256);
       int n = read(skt_fd,buffer,255);
       if (n < 0) {error("ERROR reading from socket");}
       if(buffer[0]=='\0')
       {
          hkwrite("client gose offline\n");
          break;
       }


        for(map<string,int>::iterator it = userList.begin(); it != userList.end(); ++it) {

           if(it->first!=userName) // broadcast except himself
           {

                 n=write(it->second,buffer,255);
                 write(1,it->first,strlen(it->first));
           }


        }
      }

     close(skt_fd);
     pthread_exit(NULL);

}


int main(int argc,char *argv[]){

  if (argc < 2) {
         fprintf(stderr,"ERROR, argument is port \n");
         exit(1);
     }


     hkserver server(atoi(argv[1]));
     server.hkbind();
     server.hklisten(20);

     while(1){

          hkwrite("....");
          int skfd=server.hkaccept();
          hkwrite("client come");
          pthread_t nthrd;
          int rc=pthread_create(&nthrd,NULL,Gunjan,(void *)skfd);
          if(rc){hkwrite("Error in thrad");} else {hkwrite("new client come");}
      }



    pthread_exit(NULL);


}
