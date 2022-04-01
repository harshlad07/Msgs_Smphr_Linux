#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>

int main()
{
	int shmid;
	
	struct shmid_ds d;
	
	shmid = shmget(48, 250, IPC_CREAT | 0644);
	printf("qid = %d\n", shmid);
	
	shmctl(shmid,IPC_RMID, NULL);
	return 0;
}
