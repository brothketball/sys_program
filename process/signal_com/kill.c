#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	pid_t pid;
	int sig;

	if(argc < 3)
	{
		printf("Usage:%s <pid_t> <signal>\n",argv[0]);
		return -1;
	}

	//atoi函数，将字符串转换成整型
	sig = atoi(argv[2]);
	pid = atoi(argv[1]);

	kill(pid,sig);
	
	return 0;
}
