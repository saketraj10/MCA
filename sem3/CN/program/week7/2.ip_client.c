#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12000
#define BUFFER_SIZE 1024



int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error in socket creation");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error in connection");
        exit(1);
    }
    
    printf("Enter the ip address:");
    fgets(buffer, sizeof(buffer), stdin);
    send(client_socket, buffer, strlen(buffer), 0);
    
    memset(buffer, 0, BUFFER_SIZE);
    int read_result = recv(client_socket, buffer, sizeof(buffer), 0);
    if (read_result < 0) {
            perror("Error in reading from server");
            exit(1);
        } else if (read_result == 0) {
            printf("Server disconnected\n");
            exit(1);
        }

        printf("Server found class: %s", buffer);
     	printf("session ended\n");
            

    close(client_socket);

    return 0;
}

