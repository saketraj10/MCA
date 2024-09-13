#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define MIN_BALANCE 1000.00

// Account structure
typedef struct {
    int account_no;
    int pin;
    float balance;
} Account;

Account accounts[MAX_CLIENTS] = {
    {123456, 1234, 1500.00},
    {234567, 2345, 2500.00},
    {345678, 3456, 3500.00},
    {456789, 4567, 4500.00},
    {567890, 5678, 5500.00}
};

int find_account(int account_no, int pin) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (accounts[i].account_no == account_no && accounts[i].pin == pin) {
            return i;
        }
    }
    return -1;  // Not found
}

void process_client(int new_socket) {
    int account_no, pin;
    float withdraw_amount;
    char buffer[1024] = {0};
    int valread = read(new_socket, buffer, sizeof(buffer));
    sscanf(buffer, "%d %d %f", &account_no, &pin, &withdraw_amount);

    int index = find_account(account_no, pin);
    if (index == -1) {
        strcpy(buffer, "Invalid Account Number or PIN\n");
    } else if (accounts[index].balance - withdraw_amount < MIN_BALANCE) {
        strcpy(buffer, "Not enough balance to maintain minimum balance\n");
    } else {
        accounts[index].balance -= withdraw_amount;
        snprintf(buffer, sizeof(buffer), "Withdrawal successful. Remaining Balance: %.2f\n", accounts[index].balance);
    }

    send(new_socket, buffer, strlen(buffer), 0);
    close(new_socket);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
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
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        process_client(new_socket);
    }

    return 0;
}