#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12000
#define BUFFER_SIZE 1024


void handle_client(int client_socket, int i) {
    char buffer[BUFFER_SIZE];
    printf("Client %d connected\n",i);
    while (1) {
        int read_size = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (read_size <= 0) {
            printf("Client disconnected\n");
            break;
        }

        buffer[read_size] = '\0';
        printf("Client %d: %s", i,buffer);
	if (strcmp(buffer, "exit\n") == 0) {
            printf("Chat ended\n");
            break;
        }
        printf("Server message to client %d: ", i);
        fgets(buffer, BUFFER_SIZE, stdin);
        send(client_socket, buffer, strlen(buffer), 0);
     
    }
    sleep(2);
    close(client_socket);
    
}

int main() {
    int server_socket, new_socket, i=0;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    pid_t pid;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error in socket creation");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error in binding");
        exit(1);
    }

    if (listen(server_socket, 2) == 0) {
        printf("Listening at port %d\n", PORT);
    } else {
        printf("Error in listening");
    }

    addr_size = sizeof(new_addr);

    while(1) {
        new_socket = accept(server_socket, (struct sockaddr*)&new_addr, &addr_size);
	i++;
        pid = fork();            // Fork a child process to handle this client
        if (pid == 0) {
            close(server_socket);
            handle_client(new_socket, i);
            close(new_socket);  
            exit(0); 
        } 
        
        else {
        
        close(new_socket); 
        
        }
        
    }
     
    close(server_socket);
    return 0;
}

