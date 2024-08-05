//program to demonstrate the concept of parent & child processes using fork () system call in which the parent reads a file name from the keyboard and child process uses the file name and reads first 10 characters from the file.
// Saket Raj

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(){
        pid_t pid;
        char filename[20];
        int fd;
        char buffer[11];

        printf("Enter the file name: ");
        scanf("%s", filename);

        pid = fork();

        if(pid<0){
                perror("Fork failed");
                return 1;
        }
        else if(pid==0){
                FILE* file = fopen(filename, "r");
                if(file==NULL){
                        perror("Error opening file");
                        return 1;
                }
                fread(buffer,sizeof(char), 10, file);
                printf("Child: First 10 characters from the file: %s\n", buffer);
                fclose(file);
        }
        else{
                wait(NULL);
                printf("Parent: Child process completed.\n");
        }
        return 0;
}