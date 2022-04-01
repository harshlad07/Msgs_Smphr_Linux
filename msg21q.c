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
	
	m1.t=10;
	
	for(i-0;i<100;i++)
	{
		m1.b[i] = 'a';
		m2.t=20;
	}
	
	for(i=0; i<100;i++)
	{
		m2.b[i] = 'b';
	}
	
	i = msgsnd(qid, &m1, sizeof(msg), 0);
	
	printf("\nReturn value - %d\n", i);
	
	i = msgsnd(qid, &m2, sizeof(msg), 0);
	
	printf("\nReturn value - %d\n", i);
	return 0;
}
