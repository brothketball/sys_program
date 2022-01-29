#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

struct msgbuf{
	long mtype;
	char mtext[128];
};

int main(void)
{
	int msgid;
	key_t key;
	struct msgbuf mbuf;

	key = ftok("./a.c",'a');
	msgid = msgget(key,0666|IPC_CREAT);

	if(msgid < 0)
	{
		printf("msgget is error!\n");
		return -1;
	}

	printf("msgget is ok and msgid is %d\n",msgid);

	msgrcv(msgid,&mbuf,128,0,0);	
	printf("mbuf.mtype is %ld\n",mbuf.mtype);
	printf("mbuf.mtext is %s\n",mbuf.mtext);

	return 0;
}
