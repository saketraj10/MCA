#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE], username[BUFFER_SIZE], password[BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost
    server.sin_port = htons(PORT);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connect failed");
        return 1;
    }
    printf("Connected to server\n");

    // Get username from server
    read(sock, buffer, sizeof(buffer));
    printf("%s", buffer);
    fgets(username, sizeof(username), stdin);
    write(sock, username, strlen(username));

    // Get password from server
    read(sock, buffer, sizeof(buffer));
    printf("%s", buffer);
    fgets(password, sizeof(password), stdin);
    write(sock, password, strlen(password));

    // Receive the result from server
    read(sock, buffer, sizeof(buffer));
    printf("%s", buffer);

    close(sock);
    return 0;
}