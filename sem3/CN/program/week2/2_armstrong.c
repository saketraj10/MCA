#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <math.h>
int main() {
    int fd[2], fd2[2]; // fd[0] - read end, fd[1] - write end

    // Create the first pipe
    if (pipe(fd) == -1) {
        printf("An error occurred while opening the pipe 1.\n");
        return 1;
    }

    // Create the second pipe
    if (pipe(fd2) == -1) {
        printf("An error occurred while opening the pipe 2.\n");
        return 2;
    }

    // Fork the process
    if (fork() > 0) {
        // Parent process
        close(fd[0]);  // Close reading end of first pipe
        close(fd2[1]); // Close writing end of second pipe

        int num;
        char msg[20];

        printf("Parent Process:\n");
        printf("Enter a Number: ");
        scanf("%d", &num);

        // Write the number to the first pipe
        if (write(fd[1], &num, sizeof(int)) == -1) {
            printf("An error occurred while writing to the pipe.\n");
            return 3;
        }
        close(fd[1]); // Close writing end of first pipe after writing

        // Read the message from the second pipe
        if (read(fd2[0], msg, sizeof(msg)) == -1) {
            printf("An error occurred while reading from the pipe.\n");
            return 4;
        }
        printf("Message from Child: %s\n", msg);
        close(fd2[0]); // Close reading end of second pipe after reading

    } else {
        // Child process
        close(fd[1]);  // Close writing end of first pipe
        close(fd2[0]); // Close reading end of second pipe

        int res, temp, sum = 0, rem;
        char message[10];

        // Read the number from the first pipe
        if (read(fd[0], &res, sizeof(int)) == -1) {
            printf("An error occurred while reading from the pipe.\n");
            return 5;
        }
        close(fd[0]); // Close reading end of first pipe after reading

        printf("Child Process:\n");
        printf("Received Number: %d\n", res);

        // Check if the number is an Armstrong number
        temp = res;
        int t = res;
        int p = 0;
        while(t>0){
                t /= 10;
                p++;
        }
        while (temp > 0) {
            rem = temp % 10;
            sum += pow(rem, p);
            temp /= 10;
        }

        if (res == sum) {
            strcpy(message, "YES");
        } else {
            strcpy(message, "NO");
        }

        // Write the message to the second pipe
        if (write(fd2[1], message, sizeof(message)) == -1) {
            printf("An error occurred while writing to the pipe.\n");
            return 6;
        }
        close(fd2[1]); // Close writing end of second pipe after writing
    }

    return 0;
}