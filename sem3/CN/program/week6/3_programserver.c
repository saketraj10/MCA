// udp_server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define CHUNK_SIZE 10

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    FILE *file;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Fill server information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("UDP server is running and waiting for file requests...\n");

    // Infinite loop to receive file name and send file content
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);

        // Receive file name from client
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL,
                         (struct sockaddr *)&client_addr, &addr_len);
        buffer[n] = '\0';  // Null-terminate the message
        printf("Requested file: %s\n", buffer);

        // Try to open the file
        file = fopen(buffer, "r");
        if (file == NULL) {
            strcpy(buffer, "file-not found");
            sendto(sockfd, buffer, strlen(buffer), MSG_CONFIRM,
                   (const struct sockaddr *)&client_addr, addr_len);
            printf("File not found. Sent error message to client.\n");
        } else {
            // File exists, start sending its contents 10 characters at a time
            while (fgets(buffer, CHUNK_SIZE + 1, file) != NULL) {
                sendto(sockfd, buffer, strlen(buffer), MSG_CONFIRM,
                       (const struct sockaddr *)&client_addr, addr_len);
                memset(buffer, 0, BUFFER_SIZE);
            }
            // Send a special marker to indicate end of file transfer
            strcpy(buffer, "EOF");
            sendto(sockfd, buffer, strlen(buffer), MSG_CONFIRM,
                   (const struct sockaddr *)&client_addr, addr_len);
            printf("File sent successfully.\n");
            fclose(file);
        }
    }

    close(sockfd);
    return 0;
}