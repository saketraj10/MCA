#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    int account_no, pin;
    float withdraw_amount;

    printf("Enter Account Number: ");
    scanf("%d", &account_no);
    printf("Enter PIN: ");
    scanf("%d", &pin);
    printf("Enter Withdrawal Amount: ");
    scanf("%f", &withdraw_amount);

    snprintf(buffer, sizeof(buffer), "%d %d %f", account_no, pin, withdraw_amount);
    send(sock, buffer, strlen(buffer), 0);

    // Receive response from server
    int valread = read(sock, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    close(sock);
    return 0;
}