#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12000
#define BUFFER_SIZE 1024


void handle_client(int client_socket, int i) {
    
    char buffer[BUFFER_SIZE];
    char str[BUFFER_SIZE];
    printf("Client %d connected\n",i);
    
        int read_result = recv(client_socket, buffer, sizeof(buffer), 0);
        if (read_result < 0) {
            perror("Error in reading from client");
            exit(1);
        } else if (read_result == 0) {
            printf("Client disconnected\n");
            exit(1);
        }

        printf("Received from client %d\n", i);
        printf("%s\n", buffer);
        int ip=0;
	for(int i=0; buffer[i]!='\0'&&buffer[i]!='.'; i++)   
       		ip=(ip*10)+(buffer[i]-'0');
    	if(ip>=0&&ip<=127)
        	strcpy(str,"Class A Mask:255.0.0.0\n");
    	else if(ip>=128&&ip<=191)
        	strcpy(str,"Class B Mask:255.255.0.0\n");
    	else if(ip>=192&&ip<=223)
        	strcpy(str,"Class C Mask:255.255.255.0\n");
    	else if(ip>=224&&ip<=239)
        	strcpy(str,"Class D\n");
    	else if(ip>=240&&ip<=255)
        	strcpy(str,"Class E \n");
    	else 
        	strcpy(str,"Class Invalid\n");

        send(client_socket, str, strlen(str), 0);
        printf("Calculated class:%s", str);
        printf("Ending the connection\n");
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
            printf("waitng for next connection\n");  
            exit(0); 
        } 
        
        else {
        
        close(new_socket); 
        
        }
        
    }
     
    close(server_socket);
    return 0;
}

