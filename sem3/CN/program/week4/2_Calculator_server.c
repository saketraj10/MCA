#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
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
	int n,msqid;
	struct msgbuf buf;
	int len=sizeof(buf)-sizeof(long);
	buf.mtype=1;
	msqid = msgget(1234, 0666);
	msgrcv(msqid, &buf,len, 1, 0);
	float a=buf.num[0],b=buf.num[1],ans;
	char c=buf.op;
	switch(c)
	{
		case '+': 
			ans=a+b;
			break;
		case '-': 
			ans=a-b;
			break;
		case '*': 
			ans=a*b;
			break;
		case '/': 
			ans=a/b;
			break;
	}
	buf.num[3]=ans;
	buf.mtype=2;
	printf("%f%c%f=%f\n",a,c,b,ans);
	if (msgsnd(msqid, &buf, len, IPC_NOWAIT)>=0)
		printf("Message Sent\n");
	return 0;
}
