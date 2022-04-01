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
#include<sys/sem.h>

#define KEY (1492)

int main()
{
	int id;
	
	union semun
	{
		int val;
		struct semid_ds *b;
		unsigned short *arr;
	}a;
	
	a.val = 1;
	
	id = semget(KEY, 1, 0666|IPC_CREAT);
	
	if(id<0)
	{
		fprintf(stderr, "Unable to obtain semaphor\n");
		exit(0);
	}
	
	if(semctl(id, 0, SETVAL, a))
	{
		fprintf(stderr, "Cannot set semaphor value\n");
	}
	else
	{
		fprintf(stderr, "Semaphor %d initialized\n", KEY);
	}
	return 0;
}
