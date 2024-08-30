#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	mkfifo("e_bill", 0777);
	long int id;
	int units;
	double bill_amt;
	int fd = open("e_bill", O_WRONLY);
	printf("Enter Customer Number \n");
	scanf("%ld",&id);
	printf("Enter units consumed\n");
	scanf("%d",&units);
	write(fd, &units, sizeof(units));
	close(fd);
	fd = open("e_bill", O_RDONLY);
	read(fd, &bill_amt, sizeof(bill_amt));
	printf("Bill amount is %lf\n",bill_amt);
	close(fd);
	return 0;
}
