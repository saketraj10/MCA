#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


#define MAXVAL 20

void main()
{
   pid_t cpid;
   int fd[2];

    char fn[MAXVAL], buff[100];

   printf("Enter a filename:");
   gets(fn);
   
    printf("Entered File Name = %s\n",fn);

     pipe(fd);

    if((cpid=fork())==-1) { perror("FORKING ERROR"); exit(1); }

    if(cpid>0) 
    {
     printf("PARENT PROCESS....\n");
     printf("Entered file name = %s\n",fn);
     }

     if(cpid==0)
     {
      printf("CHILD PROCESS....\n");
      printf("Entered file name = %s\n",fn);
     }  
     
}
   
     
