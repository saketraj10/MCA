#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
struct Array
{
	int arr[100];
	int n;
}a;
struct msg_Buffer
{
	long msg_type;
	struct Array a;
}message;
void main()
{
	key_t key;
	int msgid;
	key = 1001;
	msgid = msgget(key,0666|IPC_CREAT);
	message.msg_type = 1;
	printf("\nWritting Data : ");
	printf("\nEnter the size of the array : ");
	scanf("%d",&message.a.n);
	printf("\nEnter the array elements: ");
	for(int i=0;i<message.a.n;i++)
	{
		scanf("%d",&message.a.arr[i]);
	}
	printf("\nArray: ");
	for(int i=0;i<message.a.n;i++)
	{
		printf("%d ",message.a.arr[i]);
	}
	msgsnd(msgid,&message,sizeof(message),0);
	printf("\nData sent successfully");
	key = 1002;
	msgid = msgget(key,0666|IPC_CREAT);
	message.msg_type = 1;
	msgrcv(msgid,&message,sizeof(message),1,0);
	printf("\nSorted Array: ");
	for(int i=0;i<message.a.n;i++)
	{
		printf("%d ",message.a.arr[i]);
	}
	msgctl(msgid, IPC_RMID, NULL);
}
