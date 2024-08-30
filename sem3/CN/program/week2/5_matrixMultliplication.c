#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main() {
    int fd[2], fd2[2];

    // Create the first pipe
    if(pipe(fd) == -1 || pipe(fd2) == -1) {
        printf("\n An error occurred while opening the pipe.");
        return 1;
    }

    int pid = fork(); // Create a child process

    if(pid > 0) {  // Parent process
        close(fd[0]);  // Close the read end of the first pipe
        close(fd2[1]); // Close the write end of the second pipe

        int row, col;
        printf("Parent process\n");
        printf("\nEnter the size of the matrix: \nrow: ");
        scanf("%d", &row);
        printf("col: ");
        scanf("%d", &col);

        int matrix[row][col];
        int result[row][col];

        printf("\nEnter the elements of the matrix:\n");
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        // Write matrix dimensions and matrix data to the pipe
        write(fd[1], &row, sizeof(int));
        write(fd[1], &col, sizeof(int));
        write(fd[1], matrix, sizeof(int) * row * col);
        close(fd[1]);  // Close the write end of the first pipe

        // Read the processed matrix from the child
        if(read(fd2[0], result, sizeof(int) * row * col) == -1) {
            printf("\n An error occurred while reading.");
            return 2;
        }

        printf("\nResultant matrix after multiplication received from child:\n");
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }

        close(fd2[0]);  // Close the read end of the second pipe

    } else if(pid == 0) {  // Child process
        close(fd[1]);  // Close the write end of the first pipe
        close(fd2[0]); // Close the read end of the second pipe

        int row, col, mul_num;
        read(fd[0], &row, sizeof(int));
        read(fd[0], &col, sizeof(int));

        int arr[row][col];
        read(fd[0], arr, sizeof(int) * row * col);

        printf("\nChild process\n");
        printf("Enter the multiplication number: ");
        scanf("%d", &mul_num);

        // Multiply each element by the given number
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                arr[i][j] *= mul_num;
            }
        }

        close(fd[0]);  // Close the read end of the first pipe

        // Write the modified matrix back to the parent
        if(write(fd2[1], arr, sizeof(int) * row * col) == -1) {
            printf("\n An error occurred while writing.");
            return 2;
        }

        close(fd2[1]);  // Close the write end of the second pipe

    } else {
        printf("\n Fork failed.");
        return 3;
    }

    return 0;
}