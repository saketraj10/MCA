#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define MSGSIZE 14

int main()
{
	 // char* msg1="Hello World 1";
 	  char inbuf[MSGSIZE];
	  int p[2],pid;
  	system("clear");	
	pipe(p);
	pid=fork();
	if (pid>0)
	{
		close(p[0]);	
		char* msg1="Hello World 1";
		write(p[1] ,msg1 ,MSGSIZE);
	}
	
	if (pid==0)

	{
		close(p[1]);	
		read(p[0] ,inbuf ,MSGSIZE);
		printf(" In child %s",inbuf);
	}
	  exit(0);
}
