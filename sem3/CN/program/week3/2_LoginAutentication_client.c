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
	char arr1[2][20],arr2[20];
	int flag=0;
	printf("Opening login_pipe\n");
	int fd = open(fifo_pipe, O_WRONLY);
	printf("Enter Username \n");
	scanf("%s",&arr1[0][0]);
	printf("Enter Password \n");
	scanf("%s",&arr1[1][0]);
	printf("Writing username and password\n");
	write(fd, arr1, sizeof(arr1));
	close(fd);
	printf("Opening login_pipe in read mode\n");
	fd = open(fifo_pipe, O_RDONLY);
	printf("Reading login_pipe \n");
	read(fd, arr2, sizeof(arr2));
	printf("%s\n", arr2);
	close(fd);
	return 0;
}
