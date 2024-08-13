//program to accept an array before forking and search the array in child for an element accepted and display the result.
//Saket Raj

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
        int n;
        printf("Enter the size of array: ");
        scanf("%d", &n);

        int arr[n];

        printf("Enter %d elements: \n", n);
        for(int i=0; i<n; i++){
                scanf("%d", &arr[i]);
        }
        int search;
        printf("Enter the value to search in array: ");
        scanf("%d", &search);

        pid_t pid = fork();

        if(pid<0){
                perror("Fork failed");
                return 1;
        }
        else if(pid==0){
                int flag = 0;
                for(int i=0; i<n; i++){
                        if(search==arr[i]){
                                flag = 1;
                                break;
                        }
                }
                if(flag){
                        printf("%d is exist in array\n", search);
                }
                else{
                        printf("%d doesn't exist in array\n", search);
                }
        }
        else{
                wait(NULL);
                printf("Parent: Child process completed.\n");
        }

        return 0;
}