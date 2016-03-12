#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void *Run(void *sfd){


int skt_fd=(int)sfd;
char buffer[256];
 while(1){


       bzero(buffer,256);
       int n = read(skt_fd,buffer,255);
       if (n < 0) {error("ERROR reading from socket");}
       if(buffer[0]=='\0')
       {
          printf("client gose offline");
          break;
       }
       printf("->: %s\n",buffer);

      }

     close(skt_fd);

   pthread_exit(NULL);

}


int main(int argc,char *argv[]){

  if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }

     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;

     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);


     while(1){
     newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr,&clilen);
     pthread_t nthrd;
     int rc=pthread_create(&nthrd,NULL,Run,(void *)newsockfd);
      if(rc){printf("Error in thrad");} else {printf("new client come");}
     }


     close(sockfd);
     return 0;


}
