/*Using pipe & fork 
Parent accepts an array of integers and pass them to child through pipe. 
Child accepts an element to be searched and reads array from pipe. Performs search on the array received from parent.
*/
#include <stdio.h>
#include <unistd.h>   
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
        int     fd[2], nbytes;
        pid_t   childpid;
        char    string[] = "Hello, world!\n";
        char    readbuffer[80];
	int i,n=5;
	int a[5];
	int num;
	int flag;
        
	pipe(fd);  //pipe created fd[0],fd[1]

       if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }
//on success two set of pipes available,  one set (0,1) to child other to parent
        if(childpid == 0) //child process
        {
               // Child process closes up input side of pipe 
		printf("--Child: Numbers received");
		close(fd[1]); //close write  descriptor at child side
		read(fd[0], a, sizeof(a));
		for(i=0;i<sizeof(a)/4;i++)
			printf("%d ",a[i]);
		
		printf("\nEnter number to be searched..");
        	scanf("%d",&num);
		flag=0;
		i=0;
		do
			{
			if(a[i]==num)
				{
				printf("\nNumber found at :%d\n",i+1);
				flag=1;
				}	
				i++;
		}while(flag!=1 && i<n);
		if (flag==0) printf("\nNumber not found \n");
		}
        else
        {
	close(fd[0]);  //close read descriptor at parent side
	printf("--Parent: Enter numbers..");
	for (i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}
	write(fd[1], a, sizeof(a));
        wait(NULL);     // Parent process until child exits 
        }

        return(0);
}
