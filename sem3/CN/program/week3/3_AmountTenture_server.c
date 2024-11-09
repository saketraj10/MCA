#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
int main()
{
	float dep_amt,mat_amt;
	int years;
	int fd=open("tenture_pipe",O_RDONLY);
	read(fd,&dep_amt,sizeof(dep_amt));
	int read_r=read(fd,&years,sizeof(years));
	if(read_r>0)
	{
		printf("SERVER: MESSAGE RECEIVED!\n");
	} 
	printf("Writing message to client..\n");
	fd=open("tenture_pipe",O_WRONLY);
	if(years>0 && years<=1)
	{
		mat_amt=dep_amt*0.05;
		write(fd,&mat_amt,sizeof(mat_amt));
	}
	else if(years>1 && years<=2)
	{
		mat_amt=dep_amt*0.06;
		write(fd,&mat_amt,sizeof(mat_amt));
	}
	else if(years>2 && years<=3)
	{
		mat_amt=dep_amt*0.07;
		write(fd,&mat_amt,sizeof(mat_amt));
	}
	else
	{
		mat_amt=dep_amt*0.08;
		write(fd,&mat_amt,sizeof(mat_amt));
	}
	return 0;
}

