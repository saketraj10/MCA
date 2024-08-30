#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 50
void die(char *s)
{
	perror(s);
	exit(1);
}
struct msgbuf
{
	long mtype;
	int flag;
	int no,category;
};
int main()
{
	int msqid;
	key_t key;
	struct msgbuf rbuf;
	size_t buflen;
	int tickets[5][2]={{1,20},{2,20},{3,20},{4,20},{5,20}};
	key =104;
	if((msqid= msgget(key,0666|IPC_CREAT))<0)
		die("msgget()");
	printf(" msqid %d \n",msqid);
	int rcv_byt,k;
	int sizebyte_rcv=sizeof(rbuf)-sizeof(long);
	if((rcv_byt=msgrcv(msqid,&rbuf,sizebyte_rcv,1,0) )<0 )
		die("msgrcv");
	printf("%d %d",rbuf.no,rbuf.category);
	if(rbuf.no<=20)
	{
		for(int i=0;i<5;i++)
		{
			if(rbuf.category==tickets[i][0])
			{
				tickets[i][1]-=rbuf.no;
				break;
			}
		}
	}
	else
	{
		rbuf.flag=1;
	}
	printf(" received byte %d %d\n",rcv_byt,sizebyte_rcv);

	int snd_byt=sizeof(rbuf)-sizeof(long);
	int num;
	rbuf.mtype=2;
	if((num=(msgsnd(msqid,&rbuf,snd_byt, IPC_NOWAIT) ))<0 )
	{
		die("msgget");
	}
	else
	{
		printf("\nMessage Sent\n");
		printf("%d",num);
	} 
	return 0;
}
