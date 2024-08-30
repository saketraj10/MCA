#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    int fd1[2], fd2[2]; // fd1 - parent to child; fd2 - child to parent

    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        printf("An error occurred while opening the pipes.\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid > 0) { // Parent process
        printf("Parent Process: \n");
        close(fd1[0]); // Close reading end of pipe1
        close(fd2[1]); // Close writing end of pipe2

        int arr[100], n;

        printf("Enter the size of the array: ");
        scanf("%d", &n);

        printf("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        // Send the array size and array to the child
        write(fd1[1], &n, sizeof(int));
        write(fd1[1], arr, sizeof(int) * n);

        close(fd1[1]); // Close writing end after sending

        // Wait for the child to process and send back the even numbers
        wait(NULL);

        int evenArray[100], evenCount;

        // Read the size of the even numbers array from the child
        read(fd2[0], &evenCount, sizeof(int));
        // Read the even numbers array
        read(fd2[0], evenArray, sizeof(int) * evenCount);

        close(fd2[0]); // Close reading end after receiving

        printf("Even numbers array from Child: ");
        for (int i = 0; i < evenCount; i++) {
            printf("%d ", evenArray[i]);
        }
        printf("\n");

    } else if (pid == 0) { // Child process
        close(fd1[1]); // Close writing end of pipe1
        close(fd2[0]); // Close reading end of pipe2

        int n, arr[100], evenArray[100], evenCount = 0;

        // Read the size of the array from the parent
        read(fd1[0], &n, sizeof(int));
        // Read the array from the parent
        read(fd1[0], arr, sizeof(int) * n);

        close(fd1[0]); // Close reading end after receiving

        printf("Child Process: \n");
        // Filter out the even numbers
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                evenArray[evenCount++] = arr[i];
            }
        }

        // Send the size of the even numbers array back to the parent
        write(fd2[1], &evenCount, sizeof(int));
        // Send the even numbers array back to the parent
        write(fd2[1], evenArray, sizeof(int) * evenCount);

        close(fd2[1]); // Close writing end after sending

    } else {
        printf("Fork failed.\n");
        return 2;
    }

    return 0;
}