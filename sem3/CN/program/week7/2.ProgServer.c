#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Function to authenticate user
int authenticate(char *username, char *password) {
    FILE *file = fopen("user.txt", "r");
    if (!file) {
        printf("Could not open user.txt\n");
        return 0;
    }

    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), file)) {
        // Split the line by ',' and ';'
        char *file_username = strtok(line, ",");
        char *file_password = strtok(NULL, ";");

        // Remove trailing newlines or spaces
        file_password[strcspn(file_password, "\n")] = 0;

        // Check if username and password match
        if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) {
            fclose(file);
            return 1; // Successful login
        }
    }

    fclose(file);
    return 0; // Login denied
}

// Handle communication with the client
void *client_handler(void *socket_desc) {
    int client_sock = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    char username[BUFFER_SIZE], password[BUFFER_SIZE];
    
    // Ask for username
    write(client_sock, "Enter username: ", strlen("Enter username: "));
    read(client_sock, username, sizeof(username));
    username[strcspn(username, "\n")] = 0; // Remove newline character

    // Ask for password
    write(client_sock, "Enter password: ", strlen("Enter password: "));
    read(client_sock, password, sizeof(password));
    password[strcspn(password, "\n")] = 0; // Remove newline character

    // Authenticate user
    if (authenticate(username, password)) {
        write(client_sock, "Successful login\n", strlen("Successful login\n"));
    } else {
        write(client_sock, "Login Denied\n", strlen("Login Denied\n"));
    }

    close(client_sock);
    free(socket_desc);
    return NULL;
}

int main() {
    int server_sock, client_sock, c;
    struct sockaddr_in server, client;
    
    // Create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        printf("Could not create socket\n");
        return 1;
    }
    printf("Socket created\n");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }
    printf("Bind done\n");

    // Listen for incoming connections
    listen(server_sock, MAX_CLIENTS);
    printf("Waiting for incoming connections...\n");

    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(server_sock, (struct sockaddr *)&client, (socklen_t *)&c))) {
        printf("Connection accepted\n");

        pthread_t client_thread;
        int *new_sock = malloc(1);
        *new_sock = client_sock;

        // Create a new thread for each client
        if (pthread_create(&client_thread, NULL, client_handler, (void *)new_sock) < 0) {
            perror("Could not create thread");
            return 1;
        }

        printf("Handler assigned\n");
    }

    if (client_sock < 0) {
        perror("Accept failed");
        return 1;
    }

    return 0;
}