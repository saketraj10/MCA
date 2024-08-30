#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        close(fd[0]); // Close reading end of pipe

        char str[100];
        printf("Parent Process: \n");
        printf("Enter the string: ");
        scanf("%s", str);

        int len = strlen(str);
        write(fd[1], &len, sizeof(int)); // Write the length of the string
        write(fd[1], str, sizeof(char) * len); // Write the string itself
        close(fd[1]); // Close writing end of pipe

    } else if (pid == 0) {
        // Child process
        close(fd[1]); // Close writing end of pipe

        int len;
        read(fd[0], &len, sizeof(int)); // Read the length of the string

        // Dynamically allocate memory for the string
        char *str1 = (char *)malloc(len + 1);
        if (str1 == NULL) {
            perror("malloc failed");
            exit(1);
        }

        read(fd[0], str1, sizeof(char) * len); // Read the string itself
        str1[len] = '\0'; // Null-terminate the string
        close(fd[0]); // Close reading end of pipe

        int digits = 0, characters = 0;

        for (int i = 0; str1[i] != '\0'; i++) {
            if (isdigit(str1[i])) digits++;
            if (isalpha(str1[i])) characters++;
        }

        printf("Child Process: \n");
        printf("String: %s\n", str1);
        printf("Number of digits: %d\n", digits);
        printf("Number of characters: %d\n", characters);

        free(str1); // Free allocated memory

    } else {
        // Fork failed
        perror("Fork failed");
        return 1;
    }

    return 0;
}