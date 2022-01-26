#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

void main()
{
socklen_t len;
int socketfd;
struct sockaddr_in servaddr,cliaddr;
socketfd=socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=INADDR_ANY;
servaddr.sin_port=htons(5000);
char buff[1024];
connect(socketfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
for(;;)
{
bzero(&buff,sizeof(buff));
printf("\n enter a string :");
scanf("%s",buff);
if(strcmp(buff,"bye")==0)
{
exit(0);
}
else
{
write(socketfd,buff,strlen(buff));
bzero(&buff,sizeof(buff));
}

read(socketfd,buff,sizeof(buff));
printf("\n server : %s",buff);
}
close(socketfd);

}
