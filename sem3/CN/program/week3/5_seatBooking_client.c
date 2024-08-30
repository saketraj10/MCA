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
	char name[20],source[20],dest[20];
	int seats;
	float amt;
	printf("Enter the passenger name : ");
	scanf("%s",name);
	printf("Enter the source : ");
	scanf("%s",source);
	printf("Enter the destination : ");
	scanf("%s",dest);
	printf("Enter the number of seats : ");
	scanf("%d",&seats);
	mkfifo("seatBook_pipe",0777);
	int fd=open("seatBook_pipe",O_WRONLY);
	write(fd,source,sizeof(source));
	write(fd,dest,sizeof(dest));
	write(fd,&seats,sizeof(seats));
	close(fd);
	printf("CLIENT :READING THE MESSAGE FROM THE SERVER\n");
	fd = open("seatBook_pipe",O_RDONLY);
	read(fd,&amt,sizeof(amt));
	if(amt==0.0)
		printf("Seats not available..\n");
	else
	{
		printf("\nCustomer name : %s",name);
		printf("\nSource : %s Destination : %s",source,dest);
		printf("\nNo. of seats : %d",seats);
		printf("\nBill Amount : %f\n",amt);
	}
	close(fd);
	return 0;
}
