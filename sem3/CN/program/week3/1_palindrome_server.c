
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
int main()
{
	int fd,fd1,n,flag=1;
	char result[50],str1[50];
	fd=open("testpipe",O_RDONLY);
	if(fd<0)
		printf("\nPipe open failed");
	n=read(fd,str1,sizeof(str1));
	if(n>0)
	printf("\nString received: %s\n\n",str1);
	int len=strlen(str1);
	for(int i=0;i<len;i++)
	{
		if(str1[i]!=str1[len-i-1])
		{
			flag=0;
		}
		else
		{
			flag=1;
		}
	}
	if(flag==1)
		strcpy(result,"YES");
	else
		strcpy(result,"NO");
	close(fd);
	fd1=open("testpipe",O_WRONLY);
	if(fd1<0)
		printf("\nFailed");
	n=write(fd1,result,sizeof(result));	
	if(n<0)
		printf("\nWrite failed");
	close(fd1);
	return 0;
}
