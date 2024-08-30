#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct msgbuf
{
	long mtype;
	char text[100];
};
int main()
{
	int msqid;
	char temp[100]="";
	struct msgbuf buf;
	int len=sizeof(buf)-sizeof(long);
	buf.mtype=1;
	msqid = msgget(1234, 0666);
	msgrcv(msqid, &buf,len, 1, 0);
	for(int i=0;buf.text[i]!='\0';i++)
		temp[i]=buf.text[i]+1;
	printf("%s %s\n",buf.text,temp);
	strcpy(buf.text,temp);
	buf.mtype=2;
	if (msgsnd(msqid, &buf,len, IPC_NOWAIT)>=0)
		printf("Message Sent\n");
	return 0;
}
