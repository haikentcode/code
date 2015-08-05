#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>



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




int main(int argc,char *argv[]){ // arg(2)->ip port

  if(argc<4){msg("argument is ip and port");exit(0);}

    int s_skt_fd;
    int port;
    struct hostent *server;
    struct sockaddr_in serv_addr; 
  
   port=atoi(argv[2]);
   s_skt_fd=socket(AF_INET,SOCK_STREAM,0);
   if(s_skt_fd<0) msg("error opening socket"); 
   server=gethostbyname(argv[1]); 
  if(server<0) msg("error no such host"); 
  serv_addr.sin_family=AF_INET;
  bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
  //sin_addr.s_addr=inet_addr("127.0.0.2")

  serv_addr.sin_port=htons(atoi(argv[2]));

   int b=connect(s_skt_fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

  if(b<0) msg("Error on connecting");



  int fd=open(argv[3]);

  int i=0;
 while(i<100)
  {

   i++;
   char buf[1024];

   read(fd,buf,1024);
   write(s_skt_fd,buf,1024);       

  }








}