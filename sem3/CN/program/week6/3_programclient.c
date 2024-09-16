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
    char file_name[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);
    FILE *output_file;

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

    // Get the file name from the user
    printf("Enter the name of the file to request: ");
    fgets(file_name, BUFFER_SIZE, stdin);
    file_name[strcspn(file_name, "\n")] = 0;  // Remove newline character

    // Send the file name to the server
    sendto(sockfd, file_name, strlen(file_name), MSG_CONFIRM,
           (const struct sockaddr *)&server_addr, addr_len);

    // Prepare to write to a new file locally
    output_file = fopen("copied_file.txt", "w");
    if (output_file == NULL) {
        perror("Failed to create local file");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive file data from server
    while (1) {
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL,
                         (struct sockaddr *)&server_addr, &addr_len);
        buffer[n] = '\0';  // Null-terminate the message

        // Check if file was not found on the server
        if (strcmp(buffer, "file-not found") == 0) {
            printf("Server: File not found. Exiting.\n");
            break;
        }

        // Check if end of file is reached
        if (strcmp(buffer, "EOF") == 0) {
            printf("File transfer complete. Data saved to 'copied_file.txt'.\n");
            break;
        }

        // Display and write the received data to local file
        printf("%s", buffer);
        fputs(buffer, output_file);
    }

    fclose(output_file);
    close(sockfd);
    return 0;
}