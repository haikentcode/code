#include <cstdio>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <iostream>



using namespace std;

void error(const char *msg){

	perror(msg);
	exit(0);
}


int readLine(int fd, char *buf, int n)
{
	int s=0;
	char ch;
   do{
        s++;    
        if(read(fd,&ch,1)==1)
        {
        	*buf++ = ch;
        }   

     } 	
    while(ch!='\n' && s<n);

    *buf='\0';
   

    return s;
}

class hkserver{

  int s_skt_fd;
  int c_skt_fd;
  int port;
  socklen_t clilen;
  struct sockaddr_in serv_addr,cli_addr;
  int qlength;
 
public:
	   hkserver(int p)
	   {
          port=p;
          qlength=10;  
          s_skt_fd=socket(AF_INET,SOCK_STREAM,0);
          
          if(s_skt_fd<0)
                error("error opening sockdt");

          serv_addr.sin_family=AF_INET;
          serv_addr.sin_addr.s_addr=INADDR_ANY;
          serv_addr.sin_port=htons(port);        
         
           int b=bind(s_skt_fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

           if(b<0) error("error on binding");         

	   }


	   void start(){

               listen(s_skt_fd,qlength);
               
               clilen=sizeof(cli_addr);
               c_skt_fd=accept(s_skt_fd,(struct sockaddr *)&cli_addr,&clilen);

               if(c_skt_fd<0) error("error on accepting");

           }


      void sendMsg(const char *s){
           
         int n=write(c_skt_fd,s,strlen(s));
         
         if(n<0) error("error in writing msg");

      } 


    char * getMsg(){
         
         char buffer[1024];
        
        int n=readLine(c_skt_fd,buffer,1024);
        
        if(n<0) error("error in reading msg");

        return &buffer[0];                 
    }

   ~hkserver()
   {

   	close(s_skt_fd);
   	close(c_skt_fd);
   }


 





};



int main(int argc,char *argv[]){ // arg(1)->port

   

   hkserver s(atoi(argv[1]));

   s.start();

   string msg=s.getMsg();

   cout<<"new clinet:"<<msg;

   s.sendMsg("hello! I am aditi\n");

}
