#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

// Function to determine the class of an IP address
void get_ip_class_and_mask(char *ip, char *ip_class, char *mask) {
    int first_octet;
    sscanf(ip, "%d", &first_octet);

    if (first_octet >= 1 && first_octet <= 126) {
        strcpy(ip_class, "A");
        strcpy(mask, "255.0.0.0");
    } else if (first_octet >= 128 && first_octet <= 191) {
        strcpy(ip_class, "B");
        strcpy(mask, "255.255.0.0");
    } else if (first_octet >= 192 && first_octet <= 223) {
        strcpy(ip_class, "C");
        strcpy(mask, "255.255.255.0");
    } else if (first_octet >= 224 && first_octet <= 239) {
        strcpy(ip_class, "D");
        strcpy(mask, "Reserved for Multicasting");
    } else if (first_octet >= 240 && first_octet <= 255) {
        strcpy(ip_class, "E");
        strcpy(mask, "Experimental Use");
    } else {
        strcpy(ip_class, "Unknown");
        strcpy(mask, "N/A");
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char ip_class[2], mask[50];

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the network address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen");
        exit(EXIT_FAILURE);
    }

    // Accept the connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept");
        exit(EXIT_FAILURE);
    }

    // Read the IP address from the client
    read(new_socket, buffer, 1024);
    printf("Received IP address: %s\n", buffer);

    // Process the IP address
    get_ip_class_and_mask(buffer, ip_class, mask);

    // Prepare the response
    char response[100];
    snprintf(response, sizeof(response), "Class: %s, Default Mask: %s", ip_class, mask);

    // Send the response to the client
    send(new_socket, response, strlen(response), 0);
    printf("Class and Default Mask sent to client.\n");

    // Close the socket
    close(new_socket);
    close(server_fd);

    return 0;
}