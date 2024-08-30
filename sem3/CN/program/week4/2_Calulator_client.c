#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct msgbuf
{
	long mtype;
	float num[3];
	char op;
};
int main()
{
	struct msgbuf buf;
	int len=sizeof(buf)-sizeof(long);
	int msqid = msgget(1234,IPC_CREAT|0777);
	buf.mtype=1;
	printf("Enter Two numbers \n");
	scanf("%f",&buf.num[0]);
	scanf("%f",&buf.num[1]);
	printf("Enter operator\n");
	scanf("%s",&buf.op);
	if (msgsnd(msqid, &buf, len, IPC_NOWAIT)>=0)
		printf("Message Sent\n");
	float ans;
	msgrcv(msqid, &buf,len, 2, 0);
	printf("%f ",buf.num[3]);
	msgctl(msqid,IPC_RMID,0);
	return 1;
}
