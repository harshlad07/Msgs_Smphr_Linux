#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>

struct mb
{
	long t;
	char d[512];
};

int main(int argc, char *argv[])
{
	struct mb b;
	int id;
	
	id=msgget(55,IPC_CREAT|0644);
	
	printf("\nId = %d\n", id);
	
	//b.t=atoi(argv[1]);
	b.t = 22;
	
	strcpy(b.d, "LAD");
	
	msgsnd(id,&b,strlen(b.d)+1, 0);

	perror("msgsend");
	
	return 0;
}
