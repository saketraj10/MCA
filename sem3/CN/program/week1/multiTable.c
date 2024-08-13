// Program to accept an integer before forking and child has to generate multiplication table corresponding to the integer.
// Saket Raj
// 230970079

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
        int n;
        printf("Enter the integer value for multiplication: ");
        scanf("%d", &n);
        pid_t pid = fork();

        if(pid<0){
                printf("Child not created\n");
                return 1;
        }
        else if(pid==0){
                printf("Child: Multiplication of %d: \n", n);
                for(int i=1; i<11; i++){
                        printf("%d\n", n*i);
                }
        }
        else{
                wait(NULL);
                printf("Parent: Child process finished\n");
        }

        return 0;
}