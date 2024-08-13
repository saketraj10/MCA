// Program to write some characters to a file and close it in the parent. Child should open the same file in child and display.
// Saket Raj
// 230970079

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    FILE *file;
    char *filename = "example.txt";
    char *message = "Hello from parent process!";

    // Parent process: Create and write to the file
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(file, "%s\n", message);
    fclose(file);

    // Fork the process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process: Open and read the file
        file = fopen(filename, "r");
        if (file == NULL) {
            perror("Error opening file in child");
            return 1;
        }

        char buffer[256];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("Child process read: %s", buffer);
        }
        fclose(file);
    } else {
        // Parent process: Wait for child to finish
        wait(NULL);
        printf("Parent: Child process finished\n");
    }

    return 0;
}