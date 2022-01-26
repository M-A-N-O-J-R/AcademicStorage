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
int socketfd,new_socketfd;
struct sockaddr_in servaddr,cliaddr;
socketfd=socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=INADDR_ANY;
servaddr.sin_port=htons(5000);
char buff[1024];
char str[1024];
bind(socketfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
len=sizeof(cliaddr);
listen(socketfd,3);
new_socketfd=accept(socketfd,(struct sockaddr*)&cliaddr,&len);
bzero(&buff,sizeof(buff));
for(;;)
{
read(new_socketfd,buff,sizeof(buff));
printf("client : %s",buff);
bzero(&buff,sizeof(buff));
printf("\n enter message: ");
scanf("%s",buff);
if(strcmp(buff,"bye")==0)
{
exit(0);
}
else
{
write(new_socketfd,buff,strlen(buff));
bzero(&buff,sizeof(buff));
}
}
close(new_socketfd);
close(socketfd);

}
