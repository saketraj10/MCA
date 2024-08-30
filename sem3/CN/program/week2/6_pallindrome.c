#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main() {
    int fd1[2], fd2[2]; // fd1: Parent to Child, fd2: Child to Parent
    pipe(fd1);
    pipe(fd2);
    int pid = fork();

    if (pid > 0) { // Parent process
        printf("Parent process: \n");
        close(fd1[0]); // Close reading end of fd1
        close(fd2[1]); // Close writing end of fd2

        char str[100];
        printf("Enter a string: ");
        scanf("%s", str);

        int len = strlen(str);
        write(fd1[1], &len, sizeof(int)); // Write the length of the string
        write(fd1[1], str, len); // Write the string
        close(fd1[1]); // Close writing end of fd1

        char result[100];
        read(fd2[0], &len, sizeof(int)); // Read the length of the result string
        read(fd2[0], result, len); // Read the result string
        result[len] = '\0'; // Null-terminate the string
        printf("Message received from child: %s\n", result);
        close(fd2[0]); // Close reading end of fd2
    }
    else if (pid == 0) { // Child process
        close(fd1[1]); // Close writing end of fd1
        close(fd2[0]); // Close reading end of fd2

        int len = 0;
        char res_str[100];
        read(fd1[0], &len, sizeof(int)); // Read the length of the string
        read(fd1[0], res_str, len); // Read the string
        res_str[len] = '\0'; // Null-terminate the string
        close(fd1[0]); // Close reading end of fd1

        printf("Child process: \n");
        int flag = 0;
        for (int i = 0; i < len / 2; i++) {
            if (res_str[i] != res_str[len - i - 1]) {
                flag = 1;
                break;
            }
        }

        char palindrome[100];
        if (flag == 0) {
            strcpy(palindrome, "PALINDROME");
        } else {
            strcpy(palindrome, "NOT PALINDROME");
        }

        len = strlen(palindrome);
        write(fd2[1], &len, sizeof(int)); // Write the length of the result string
        write(fd2[1], palindrome, len); // Write the result string
        close(fd2[1]); // Close writing end of fd2
    }

    return 0;
}