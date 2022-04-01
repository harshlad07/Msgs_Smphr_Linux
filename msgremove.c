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

int main()
{
	int qid;
	
	struct msqid_ds d;
	
	qid = msgget(49, IPC_CREAT|0644);
	
	printf("\nQid = %d\n", qid);
	
	msgctl(qid, IPC_RMID,NULL);
	return 0;
}
