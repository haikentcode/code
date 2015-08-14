#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>

using namespace std;

void msg(const char *msg){

	perror(msg);
	exit(0);
}


int readLine(int fd, char *buf, size_t n)
{
	int s=0;
	char ch;
   do{
        s++;    
        if(read(fd,&ch,1)>0)
        {
        	*buf++ = ch;
        }   

     } 	
    while(ch!='\n' && s<n);

    *buf='\0';

    return s;
   
}

class hkclient{
   
    int s_skt_fd;
    int port;
    struct hostent *server;
    struct sockaddr_in serv_addr; 
    public:
    
       hkclient(char *argv[]){
             
             
             port=atoi(argv[2]);
             s_skt_fd=socket(AF_INET,SOCK_STREAM,0);

             if(s_skt_fd<0) msg("error opening socket"); 

             server=gethostbyname(argv[1]); 

             if(server<0) msg("error no such host"); 
             serv_addr.sin_family=AF_INET;
             bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
            //sin_addr.s_addr=inet_addr("127.0.0.2")

             serv_addr.sin_port=htons(atoi(argv[2]));

            
       }


       void conct(){

             int b=connect(s_skt_fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

             if(b<0) msg("Error on connecting");

              else  cout<<"connect to server";

       } 

     void sendMsg(const char *s){
        
         int n=write(s_skt_fd,s,strlen(s));
         if(n<0) msg("error in writing msg");

      } 


    char * getMsg(int n){
         
         char buffer[1024];
         int n=readLine(s_skt_fd,buffer,n);
         if(n<0) msg("error in reading msg");    

         return &buffer[0];            
    }

  

};


int main(int argc,char *argv[]){ // arg(2)->ip port

  if(argc<3){msg("argument is ip and port");exit(0);}

  hkclient client(argv);
  client.conct();

  cout<<client.getMsg(10);
  client.sendMsg("I am hitesh");
  cout<<client.getMsg(10);
   

     



}