#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/types.h>

#define KEY 8979

int main()
{
	int qid;
	
	struct msqid_ds b;
	
	qid = msgget(32,IPC_CREAT|0644);
	
	printf("\nqid = %d", qid);
	
	msgctl(qid, IPC_STAT, &b);
	
	printf("\nHere are the details of the queue");
	printf("\nNumbers of msgs %hi\n", b.msg_qnum);
	
	printf("\nMAx no. of bytes - %hi\n", b.msg_qbytes);
	return 0;
}
