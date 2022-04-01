#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>

int main()
{
	char *p;
	int id;
	
	id = shmget(48,250,IPC_CREAT|0644);
	
	if(id<0)
	{
		perror("shmget");
		return 0;
	}
	
	printf("%d\n", id);
	p = shmat(id, 0, 0);
	printf("Enter the data");
	scanf("%s", p);
	
	return 0;
}
