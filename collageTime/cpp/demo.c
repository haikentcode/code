#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>

void error(char *msg)
{
perror(msg);
exit(1);	
}

int main(int argc ,char *argv[])
{
struct sockaddr_in serv_addr;
int socket_fd,file_fd;
char buffer[200],ch;

fflush(stdout);

socket_fd=socket(AF_INET,SOCK_STREAM,0);

if(socket_fd<0)
	error("socket on client side can not be created:");

serv_addr.sin_family=AF_INET;
serv_addr.sin_port=htons(atoi(argv[2]));
serv_addr.sin_addr.s_addr=inet_addr(argv[1]);

if(connect(socket_fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
	error("client can not be created to server:");

write(1,"enter your message to server:",strlen("enter your message to server:"));

read(0,buffer,200);

write(socket_fd,buffer,(int)strlen(buffer));

memset(buffer,'\0',200);

read(socket_fd,buffer,100);
//printf("hello = %s\n",buffer);

write(1,buffer,(int)strlen(buffer));

close(socket_fd);

return 0;

}
