#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
int main()
{
	int b[12][4]={{1,2,4000,30},{1,3,3000,30},{1,4,5000,30},{2,1,3500,30},{2,3,3000,30},{2,4,5000,30},{3,1,3500,30},{3,2,4000,30},{3,4,3000,30},{4,1,5000,30},{4,2,3500,30},{4,3,5000,30}};
	char source[20],dest[20];
	int seat;
	float amt;
	int fd=open("seatBook_pipe",O_RDONLY);
	int r=read(fd,&source,sizeof(source));
	read(fd,&dest,sizeof(dest));
	read(fd,&seat,sizeof(seat));
	if(r>0)
	{
		printf("SERVER: MESSAGE RECEIVED!\n");
	}
	int s;
	if(strcmp(source,"mangalore")==0)
		s=1;
	else if(strcmp(source,"bangalore")==0)
		s=2;
	else if(strcmp(source,"mumbai")==0)
		s=3;
	else if(strcmp(source,"delhi")==0)
		s=4;
	else
		s=0;
	int d;
	if(strcmp(dest,"mangalore")==0)
		d=1;
	else if(strcmp(dest,"bangalore")==0)
		d=2;
	else if(strcmp(dest,"mumbai")==0)
		d=3;
	else if(strcmp(dest,"delhi")==0)
		d=4;
	else
		d=0;
	printf("Writing to client..\n");
	fd=open("seatBook_pipe",O_WRONLY);
	int flag=0;
	for(int i=0;i<4;i++)
	{
		if(s==b[i][0] && d==b[i][1])
		{
			if(seat<b[i][3])
			{
				b[i][3]-=seat;
				amt=(seat*b[i][2]);
				flag=1;
				break;
			}
		}
	}
	if(flag==1)
		write(fd,&amt,sizeof(amt));
	else
	{
		amt=0.0;
		write(fd,&amt,sizeof(amt));
	}
	return 0;
}
