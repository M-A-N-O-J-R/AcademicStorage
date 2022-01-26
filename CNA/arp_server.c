#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
typedef struct ARP_PACKET
{
    int mode;
    char src_ip[50];
    char dest_ip[50];
    char src_mac[50];
    char dest_mac[50];
    char data[50];
} arp;
int main()
{
    struct sockaddr_in server, client;
    char buffer[1024];
    int client_sockets[10] = {0}, max, fd, sockfd, newfd, activity;
    int k, i, len, count;
    fd_set newfds;
    arp packet, recv_packet;
    bzero(&packet, sizeof(packet));
    packet.mode = 1;
    printf("\n\tEnter the details of packet received.\n\n");
    printf("\tDestination IP\t: ");
    scanf(" %s", packet.dest_ip);
    printf("\tSource IP\t: ");
    scanf(" %s", packet.src_ip);
    printf("\tSource MAC\t: ");
    scanf(" %s", packet.src_mac);
    printf("\t16 bit data\t: ");
    scanf(" %s", packet.data);
    printf("\nDeveloping ARP Request packet\n\n");
    printf("\t%d|%s|%s|%s|%s\n", packet.mode, packet.src_mac, packet.src_ip,
           "00:00:00:00:00:00", packet.dest_ip);
    printf("\tThe ARP Request packet is broacasted.\n\n");
    printf("Waiting for ARP Reply...\n");
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Unable to open socket.\n");
        exit(0);
    }
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);
    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("Binding failed.\n");
        exit(0);
    }
    listen(sockfd, 10);
    len = sizeof(client);
    while (1)
    {
        FD_ZERO(&newfds);        // Clears socket set.
        FD_SET(sockfd, &newfds); // Add sockfd to socket set.
        max = sockfd;
        for (i = 0; i < 10; i++)
        {
            fd = client_sockets[i];
            if (fd > 0)
            {
                FD_SET(fd, &newfds);
            }
            if (fd > max)
            { // Store the max valued FD.
                max = fd;
            }
        }
        // Wait indefinitely till any client pings.
        activity = select(max + 1, &newfds, NULL, NULL, NULL);
        if (activity < 0)
        {
            printf("Select error.\n");
            exit(0);
        }
        // if sockfd change => new connection request.
        if (FD_ISSET(sockfd, &newfds))
        {
            newfd = accept(sockfd, (struct sockaddr *)&client, &len);
            if (newfd < 0)
            {
                printf("New connection accepting failed.\n");
                exit(0);
            }
            send(newfd, (void *)&packet, sizeof(packet), 0);
            // Add the new client on an empty slot.
            for (i = 0; i < 10; i++)
            {
                if (client_sockets[i] == 0)
                {
                    client_sockets[i] = newfd;
                    break;
                }
            }
        }
        // Broadcast on all established connections
        for (i = 0; i < 10; i++)
        {
            fd = client_sockets[i];
            bzero((void *)&recv_packet, sizeof(recv_packet));
            // Check for change in FD
            if (FD_ISSET(fd, &newfds))
            {
                recv(fd, (void *)&recv_packet, sizeof(recv_packet), 0);
                // Check ARP response
                if (recv_packet.mode == 2)
                {
                    printf("\nARP Reply received: \n");
                    printf("\t%d|%s|%s|%s|%s\n", recv_packet.mode, recv_packet.src_mac,
                           recv_packet.src_ip, recv_packet.dest_ip, recv_packet.dest_mac);
                    strcpy(packet.dest_mac, recv_packet.src_mac);
                    packet.mode = 3;
                    printf("\nSending the data packet to:%s", packet.dest_mac);
                    send(newfd, (void *)&packet, sizeof(packet), 0);
                    printf("\n");
                    exit(EXIT_SUCCESS);
                }
            }
        }
    }
    close(sockfd);
    return 0;
}
