#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<strings.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main()
{
	float dep_amt,mat_amt;
	int year;
	printf("Enter the Deposite Amount:");
	scanf("%f",&dep_amt);
	printf("Enter the year:");
	scanf("%d",&year);
	mkfifo("tenture_pipe",0777);
	int fd=open("tenture_pipe",O_WRONLY);
	write(fd,&dep_amt,sizeof(dep_amt));
	write(fd,&year,sizeof(year));
	close(fd);
	printf("CLIENT :\n\tREADING THE MESSAGE FROM THE SERVER\n");
	fd = open("tenture_pipe",O_RDONLY);
	read(fd,&mat_amt,sizeof(mat_amt));
	printf("%f \n",mat_amt);
	close(fd);
	return 0;
}
