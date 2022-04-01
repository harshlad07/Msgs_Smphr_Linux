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

int sid;
union semun
{
	int val;
	struct sid_ds *b1;
	unsigned short *arr;
	struct seminfo *b2;
};

int gr(void);
int gs(void);
struct sembuf so;
union semun su;

int main()
{
	int i;
	
	sleep(3);
	
	//int sid;
	sid = semget((key_t)10, 1, 0666|IPC_CREAT);
	
	printf("\nSemaforce ID - %d", sid);
	
	su.val = 1;
	
	if(semctl(sid, 0, SETVAL, su)<0)
	{
		printf("\nError");
	}
	
	for(i=0;i<=5;i++)
	{
		gs();
		printf("\n%d got semaforce ", getpid());
		sleep(1);
		
		printf("\n%d release semaforce ", getpid());
		gr();
		sleep(1);
	}
	
	if(semctl(sid, 0, IPC_RMID, su)<0)
	{
		printf("\nfails to delete");
	}
	else
	{
		printf("\nSemaforce deleted\n");
	}
	return 0;
}

int gs(void)
{
	so.sem_num = 0;
	so.sem_op = -1;
	so.sem_flg = SEM_UNDO;
	
	if(semop(sid, &so, 1)<0)
	{
		printf("failed\n");
		return -1;
	}
}

int gr(void)
{
	so.sem_num = 0;
	so.sem_op = 1;
	so.sem_flg = SEM_UNDO;
	
	if(semop(sid, &so, 1)<0)
	{
		printf("failed\n");
		return -1;
	}
}
