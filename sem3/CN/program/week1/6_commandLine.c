// Accept two numbers and operator (+, -, *, /) as command line arguments. Perform numerical operation as per operator in the child and display the result.
// Saket Raj
// 230970079

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
        if(argc != 4)
        {
                printf("Usage: %s num1 operator num2\n", argv[0]);
                return 1;
        }

        double num1 = atof(argv[1]);
        char operator = argv[2][0];
        double num2 = atof(argv[3]);
        double result;

        pid_t pid = fork();

        if(pid<0){
                printf("Fork failed.\n");
                return 1;
        }
        else if(pid==0)
        {
                if(operator=='+')
                {
                        result = num1 + num2;
                }
                else if(operator=='-')
                {
                        result = num1 - num2;
                }
                else if(operator=='*')
                {
                        result = num1 * num2;
                }
                else if(operator=='/')
                {
                        if(num2==0){
                                printf("Child: Division by zero not allowed.\n");
                                return 1;
                        }
                        result = num1 / num2;
                }
                else
                {
                        printf("Child: Invalid operator.\n");
                        return 1;
                }
                printf("Child: Result: %lf\n", result);
        }
        else{
                wait(NULL);
                printf("Parent: Child process finished.\n");
        }

        return 0;
}