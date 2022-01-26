#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<cstdio>
#include<cstring>
#include<sys/wait.h>
#include<cstdlib>
#include<unistd.h>
#include<bits/stdc++.h>
#define maxer 16
using namespace std;
int main(int argc,char **argv)
{
socklen_t len;
int sockfd;
struct sockaddr_in servaddr,cliaddr;
int n;
char buff[1024],str[1024];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd < 0)
perror("\nsocket error\n");
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr(argv[1]);
servaddr.sin_port=htons(9002);
connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
do{
printf("\nMe: ");
cin>>str;
        bitset<maxer> q("1101");
        string x(str);
        x+="000";
        string temp(x.begin(),x.begin()+4);
        bitset<maxer> d(temp);
        d^=q;        
        for(int i=4;i<x.length();i++)
        {
            d<<=1;
            if(x[i]=='1')
                d[0]=1;
            else d[0]=0;
            if(d.test(3))
                d^=q;
        }
        string t=d.to_string();
        t=string(t.end()-3,t.end());
        x=string(str);
        x+=t;
        char *result=&x[0];
        srand(time(0));
        int l=rand()%9;
        if(l%2==1)
            result[2]=(result[2]=='0')?'1':'0';
write(sockfd,result,x.length());
n=read(sockfd,buff,sizeof(buff));
buff[n]=0;
if(strcmp(str,"!exit")==0)
printf("%s",buff);
else
printf("Ser: %s",buff);
   }while(strcmp(str,"!exit")!=0);
printf("\n\n");
close(sockfd);
return 0;
}
