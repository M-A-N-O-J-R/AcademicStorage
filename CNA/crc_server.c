#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<unistd.h>
#include<sys/wait.h>
#include<bits/stdc++.h>
#define maxer 16
using namespace std;
int main(int argc,char **argv)
{
socklen_t len;
int sockid,connfd;
pid_t pid1;
struct sockaddr_in servaddr,cliaddr;
char buff[1024];
int n;
sockid=socket(AF_INET,SOCK_STREAM,0);
if(sockid < 0)
perror("\nunable to create socket\n\n");
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=INADDR_ANY;
servaddr.sin_port=htons(9002);
bind(sockid,(struct sockaddr *)&servaddr,sizeof(servaddr));
listen(sockid,5);
    for(;;)
{
len=sizeof(cliaddr);
connfd=accept(sockid,(struct sockaddr *)&cliaddr,&len);
if(pid1=fork() == 0)
{
close(sockid);
do
{
n=read(connfd,buff,sizeof(buff));
buff[n]=0;
if(strcmp(buff,"!exit")!=0)
{
                    bitset<maxer> q("1101");
                    string temp(buff);
                    string x(temp.begin(),temp.begin()+4);
                    bitset<maxer> d(x);
                    d^=q;
                    for(int i=4;i<strlen(buff);i++)
                    {
                        d<<=1;
                        if(buff[i]=='1')
                            d[0]=1;
                        else d[0]=0;
                        if(d.test(3))
                            d^=q;
                    }
                    if(d.any())
                        write(connfd,"Error-resend",sizeof("Error-resend"));
                    else
                        write(connfd,"ACK",sizeof("ACK"));
                }
                else
                {
                    strcpy(buff,"  (Terminated)");
printf("\n  (Terminated)\n\n");
write(connfd,buff,sizeof(buff));
exit(0);
                }
             }while(strcmp(buff,"!exit")!=0);
}
}
close(connfd);
return 0;
}
