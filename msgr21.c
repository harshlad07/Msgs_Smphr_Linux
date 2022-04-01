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

typedef struct
{
	long t;
	char b[100];
}msg;

int main()
{
	int qid, i;
	
	msg m1,m2;
	
	qid=msgget(32,IPC_CREAT|0644);
	i = msgrcv(qid, &m1, sizeof(msg), 10, 0);
	
//	m1.t=10;
	
	for(i-0;i<100;i++)
	{
		printf("%c", m1.b[i]);
	}
	printf("\n");

	i = msgrcv(qid, &m2, sizeof(msg), 10, 0);
	for(i=0; i<100;i++)
	{
		printf("%c", m2.b[i]);
	}
	
	
//	printf("\nReturn value - %d\n", i);
	
	
//	printf("\nReturn value - %d\n", i);
	return 0;
}
