// udp_client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    char ip_address[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Fill server information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    printf("Enter the IP address: ");
    fgets(ip_address, BUFFER_SIZE, stdin);
    ip_address[strcspn(ip_address, "\n")] = 0;  // Remove newline character

    // Send IP address to the server
    sendto(sockfd, ip_address, strlen(ip_address), MSG_CONFIRM, 
           (const struct sockaddr *)&server_addr, addr_len);

    // Receive the class and default mask from the server
    int n = recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL, 
                     (struct sockaddr *)&server_addr, &addr_len);
    buffer[n] = '\0';  // Null-terminate the message

    // Display the server's response
    printf("Server response: %s\n", buffer);

    close(sockfd);
    return 0;
}
