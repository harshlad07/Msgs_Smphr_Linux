#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>

struct mb
{
	long t;
	char d[512];
};


int main(int argc, char **argv)
{
	int id;
	struct mb b;
	
	if(argc!=2)
	{
		printf("\nUsage ./mqr type\n");
		printf("Eg. mqr\n");
		return 0;
	}
	
	id = msgget(55,IPC_CREAT|0644);
	
	if(id<0)
	{
		perror("msgget");
		return 0;
	}
	
	msgrcv(id,&b,sizeof(b), atoi(argv[1]), 0);
	printf("Data %s\n", b.d);
	return 0;
}
