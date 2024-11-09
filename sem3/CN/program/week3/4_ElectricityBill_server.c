#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	mkfifo("e_bill", 0777);
	int units;
	double bill_amt;
	while(1)
	{
		int fd = open("e_bill", O_RDONLY);
		read(fd, &units, sizeof(units));
		close(fd);
		printf("Number of units: %d",units);
		if(units<=50)
			bill_amt=units*1;
		else if(units<=100)
			bill_amt=50+(units-50)*1.5;
		else if(units<=200)
			bill_amt=50+75+(units-100)*2;
		else
			bill_amt=50+75+200+(units-200)*3;
		fd = open("e_bill", O_WRONLY);
		write(fd,&bill_amt,sizeof(bill_amt));
		close(fd);
	}
	return 0;
}

