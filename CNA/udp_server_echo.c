#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void main()
{
socklen_t len;
int socketfd;
struct sockaddr_in servaddr,cliaddr;
char buff[1024];
socketfd=socket(AF_INET,SOCK_DGRAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=INADDR_ANY;
servaddr.sin_port=htons(5000);

bind(socketfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
len=sizeof(cliaddr);
recvfrom(socketfd,buff,sizeof(buff),0,(struct sockaddr*)&cliaddr,&len);
printf("\n message recieved from client : %s",buff);
sendto(socketfd,buff,sizeof(buff),0,(struct sockaddr*)&cliaddr,len);
close(socketfd);
}
