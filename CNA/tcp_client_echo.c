#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

int main(){
    int client_socket,connection_status;
    client_socket=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in client_address;
    client_address.sin_family=AF_INET;
    client_address.sin_addr.s_addr=INADDR_ANY;
    client_address.sin_port=htons(9000);
    if((connection_status=connect(client_socket,(struct sockaddr*) &client_address,sizeof(client_address)))==-1){
        printf("Connection not successful\n");
        return 0;
    }
    char server_response[256];
    printf("\nEnter a string: "); scanf(" %[^\n]",server_response);
    send(client_socket,server_response,sizeof(server_response),0);
    recv(client_socket,&server_response,sizeof(server_response),0);
    printf("%s\n",server_response);
    close(client_socket); 
    return 0;
}
