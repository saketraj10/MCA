#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int n,fd,fd1,write_n;
	char str[50],result[50];
	printf("Enter the string:");
	scanf("%s",str);
	if((fd=open("testpipe",O_WRONLY))<0)
	{
		printf("\nPipe opening failed\n");
		exit(1);
	}
	printf("FD: %d\n",fd);
	write_n=write(fd,str,sizeof(str)); 
	if(write_n<0)
		printf("writing to pipe failed");
	close(fd);
	if((fd1=open("testpipe",O_RDONLY))<0)
	{
		printf("\nPipe read failed");
	}
	if(n=read(fd1,result,sizeof(result))<0)
		printf("\nPipe read failed");
	printf("Entered string is palindrome :%s\n",result);
	close(fd1);
	return 0;
}
