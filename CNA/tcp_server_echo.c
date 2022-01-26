#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
int main(){
    char server_message[256];
    int server_socket,connection;
    server_socket=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_addr.s_addr=INADDR_ANY;
    server_address.sin_port=htons(9000);

    bind(server_socket,(struct sockaddr*)&server_address,sizeof(server_address));
    listen(server_socket,5);
    int client_socket;
    client_socket=accept(server_socket,NULL,NULL);
    recv(client_socket,&server_message,sizeof(server_message),0);
    strcat(server_message," Echoed from server");
    send(client_socket,server_message,sizeof(server_message),0);
    close(server_socket);
    return 0;
}
