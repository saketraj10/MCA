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
	int msgflg= IPC_CREAT | 0666;
	key_t key;
	struct msgbuf sbuf;
	size_t buflen;
	key =104;
	if((msqid= msgget(key,msgflg))<0)
		die("msgget");
	char name[20];
	int phone;
	sbuf.mtype=1;
	sbuf.flag=0;
	printf(" msqid %d \n",msqid);
	printf("Enter your name : ");
	scanf("%[^\n]",name);
	printf("\nEnter your phone number : ");
	scanf("%d",&phone);
	printf("\nEnter the ticket Category");
	printf("\n1.Comedy\n2.Horror\n3.Romance\n4.Thriller\n5.Suspense");
	printf("\nEnter your choice : ");
	scanf("%d",&sbuf.category);
	printf("\nEnter the number of tickets : ");
	scanf("%d",&sbuf.no);
	printf("dfsd : %d",sbuf.no);
	int snd_byt=sizeof(sbuf)-sizeof(long);
	int num;
	if((num=(msgsnd(msqid,&sbuf,snd_byt, IPC_NOWAIT) ))<0 )
	{
		die("msgget");
	}
	else
	{
		printf("Message Sent\n");
		printf("%d",num);
	}
	struct msgbuf rbuf;
	int rcv_byt;
	int sizebyte_rcv=sizeof(rbuf)-sizeof(long);
	if((rcv_byt=msgrcv(msqid,&rbuf,sizebyte_rcv,2,0) )<0 )
		die("msgrcv");
	printf("received byte %d %d\n",rcv_byt,sizebyte_rcv);
	if(rbuf.flag==1)
	{
		printf("Tickets not available");
	}
	else
	{
		printf("%d ticket booking successful under the name : %s",rbuf.no,name); 
	}
}
