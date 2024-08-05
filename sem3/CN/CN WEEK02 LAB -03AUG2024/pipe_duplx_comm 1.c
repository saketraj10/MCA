#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int pp[2],pc[2], pid;
	char msg1[20];
	char msg2[20];  
	char msg3[20];
	pipe(pp);
	pipe(pc);
	pid=fork();
	if(pid==0)
	{
		close(pc[0]);
		write(pc[1],"Hi Dad",6);
		msg2[6]='\0';
		close(pp[1]);
		read(pp[0],msg2,11);
		msg2[11]='\0';
		printf("chiild reading-%s\n",msg2);
		close(pc[0]);
		write(pc[1],"Thank you Dad",13);
	}
	else
	{
		close(pc[1]);
		read(pc[0],msg1,6);
		msg1[6]='\0';
		printf("Parent Reading-%s\n",msg1);
		close(pp[0]);
		write(pp[1],"Hi My Child",11); 
		close(pc[1]);
		read(pc[0],msg3,13);
		msg3[13]='\0';
		printf("Parent reading-%s\n",msg3);
	}
}
