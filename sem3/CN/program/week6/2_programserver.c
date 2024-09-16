// udp_server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to identify the class and default mask of the IP address
void identify_ip_class(char *ip_address, char *ip_class, char *default_mask) {
    unsigned int first_octet;
    sscanf(ip_address, "%u", &first_octet);

    if (first_octet >= 1 && first_octet <= 126) {
        strcpy(ip_class, "Class A");
        strcpy(default_mask, "255.0.0.0");
    } else if (first_octet >= 128 && first_octet <= 191) {
        strcpy(ip_class, "Class B");
        strcpy(default_mask, "255.255.0.0");
    } else if (first_octet >= 192 && first_octet <= 223) {
        strcpy(ip_class, "Class C");
        strcpy(default_mask, "255.255.255.0");
    } else if (first_octet >= 224 && first_octet <= 239) {
        strcpy(ip_class, "Class D (Multicast)");
        strcpy(default_mask, "N/A");
    } else if (first_octet >= 240 && first_octet <= 255) {
        strcpy(ip_class, "Class E (Experimental)");
        strcpy(default_mask, "N/A");
    } else {
        strcpy(ip_class, "Invalid IP Address");
        strcpy(default_mask, "N/A");
    }
}

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    char ip_class[50];
    char default_mask[50];
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

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

    printf("UDP server is running and waiting for IP addresses...\n");

    // Infinite loop to receive IP address and respond with class and default mask
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        
        // Receive IP address from client
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL, 
                         (struct sockaddr *)&client_addr, &addr_len);
        buffer[n] = '\0';  // Null-terminate the message

        printf("Received IP address: %s\n", buffer);

        // Identify the class and default mask of the IP address
        identify_ip_class(buffer, ip_class, default_mask);

        // Prepare the response
        sprintf(buffer, "IP Class: %s, Default Mask: %s", ip_class, default_mask);

        // Send the result back to the client
        sendto(sockfd, buffer, strlen(buffer), MSG_CONFIRM, 
               (const struct sockaddr *)&client_addr, addr_len);

        printf("Sent: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}
