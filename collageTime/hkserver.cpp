#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
using namespace std;
int main(int argc,char *argv[]){

   
         if(argc<2) return 0;
         int portno=atoi(argv[1]);

         int skt=socket(AF_INET,SOCK_STREAM,0);

         struct sockaddr_in sadd,cadd; 

        //bzero((char *)&sadd,sizeof(sadd));

         
         sadd.sin_family=AF_INET;
         sadd.sin_addr.s_addr=INADDR_ANY;
         sadd.sin_port=htons(portno);

        
        int b=bind(skt,(struct sockaddr *)&sadd,sizeof(sadd));

        if(b<0){ cout<<"eroor in binding"; return 0;}
       
        
        listen(skt,5);

        socklen_t clen=sizeof(cadd);

        int cskt=accept(skt,(struct sockaddr *)&cadd,&clen);

        if(cskt<0){cout<<"error accept";return 0;}
         
   while(true){
        char buff[256]; 
        
        int n=read(cskt,buff,255);
         buff[255]=0;

        if(n<0) cout<<"error in reading";

        cout<<"msg is:"<<buff;
        
        n=write(cskt,"love you aditi",14);
     }
        close(skt);
        close(cskt);  


}
