#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>

struct msgbuf
{
	long t;
	char data[100];
};

int main(int agrc, char *argv[])
{
	struct msgbuf b;
	struct msqid_ds d;
	
	int id;
	
	id = msgget(49,IPC_CREAT|0644);
	
	printf("\nid = %d\n", id);
	b.t = atoi(argv[1]);
	strcpy(b.data, argv[2]);
	
	msgsnd(id, &b, strlen(b.data)+1, 0);
	
	msgctl(id, IPC_STAT, &d);
	
	printf("\nHere are the details of the queue");
	printf("\nNumbers of msgs %hi\n", d.msg_qnum);
	
	printf("\nMAx no. of bytes - %hi\n", d.msg_qbytes);
	
	return 0;
}
