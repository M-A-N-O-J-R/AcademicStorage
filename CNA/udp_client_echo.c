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

len=sizeof(servaddr);
printf("\n enter message to send :");
scanf("%s",buff);
sendto(socketfd,buff,sizeof(buff),0,(struct sockaddr*)&servaddr,len);
bzero(&buff,sizeof(buff));
recvfrom(socketfd,buff,sizeof(buff),0,(struct sockaddr*)&servaddr,&len);
printf("\n echoed message: %s",buff);

close(socketfd);
}