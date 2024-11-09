#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd1[2]; // Pipe 1: Parent to Child (fd1[0] - read, fd1[1] - write)
    int fd2[2]; // Pipe 2: Child to Parent (fd2[0] - read, fd2[1] - write)

    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        printf("\nAn error occurred while opening the pipe.\n");
        return 1;
    }

    int pid = fork();

    if (pid > 0) {  // Parent process
        close(fd1[0]); // Close reading end of Pipe 1
        close(fd2[1]); // Close writing end of Pipe 2

        // Input student details
        int regno, m1, m2, m3;
        printf("\nEnter student details:\n");
        printf("Registration Number: ");
        scanf("%d", &regno);
        printf("Mark 1: ");
        scanf("%d", &m1);
        printf("Mark 2: ");
        scanf("%d", &m2);
        printf("Mark 3: ");
        scanf("%d", &m3);

        // Write data to child
        write(fd1[1], &regno, sizeof(int));
        write(fd1[1], &m1, sizeof(int));
        write(fd1[1], &m2, sizeof(int));
        write(fd1[1], &m3, sizeof(int));
        close(fd1[1]); // Close writing end after sending data

        wait(NULL); // Wait for child process to finish

        char grade[3];
        // Read grade from child
        read(fd2[0], grade, sizeof(grade));
        close(fd2[0]); // Close reading end after receiving data

        printf("\nGrade received from child: %s\n", grade);
    } else if (pid == 0) {  // Child process
        close(fd1[1]); // Close writing end of Pipe 1
        close(fd2[0]); // Close reading end of Pipe 2

        int regno, m1, m2, m3;
        float avg;
        char grade[3];

        // Read data from parent
        read(fd1[0], &regno, sizeof(int));
        read(fd1[0], &m1, sizeof(int));
        read(fd1[0], &m2, sizeof(int));
        read(fd1[0], &m3, sizeof(int));
        close(fd1[0]); // Close reading end after reading data

        // Calculate average and grade
        avg = (m1 + m2 + m3) / 3.0;
        if (avg > 90)
            strcpy(grade, "A+");
        else if (avg > 80)
            strcpy(grade, "A");
        else if (avg > 70)
            strcpy(grade, "B");
        else if (avg > 60)
            strcpy(grade, "C");
        else if (avg > 50)
            strcpy(grade, "D");
        else if (avg > 40)
            strcpy(grade, "E");
        else
            strcpy(grade, "F");

        // Send grade to parent
        write(fd2[1], grade, sizeof(grade));
        close(fd2[1]); // Close writing end after sending data
    } else {
        printf("\nFork failed.\n");
        return 1;
    }

    return 0;
}