#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	char* fifo_pipe = "login_pipe";
	mkfifo(fifo_pipe, 0777);
	char arr1[2][20],arr2[20]="Login Access Denied",users[3][2][20]={{"admin","1234"},{"admin","admin123"},{"admin","password"}};
	while(1)
	{
		int flag=0;
		int fd = open(fifo_pipe, O_RDONLY);
		read(fd, arr1, sizeof(arr1));
		close(fd);
		for(int i=0;i<3;i++)
		{
			if(strcmp(arr1[0],users[i][0])==0)
				if(strcmp(arr1[1],users[i][1])==0)
				{
					strcpy(arr2,"Welcome ");
					strcat(arr2, arr1[0]);
					break;
				}
		}
	fd = open(fifo_pipe, O_WRONLY);
	write(fd,arr2,sizeof(arr2));
	close(fd);
	}
	return 0;
}

