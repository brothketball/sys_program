#include<stdio.h>
#include<unistd.h>

int main(void)
{
	pid_t pid;
	pid = fork();

	if(pid < 0)
	{
		printf("fork is error!\n");
		return -1;
	}

	// 父进程
	if(pid > 0)
	{
		printf("This is parent, parent id is %d\n",getpid());
	}

	// 子进程，子进程等待一会，让父进程先结束，再打印父进程的PID
	if(pid == 0)
	{
		sleep(2);
		printf("This is child, chhild id is %d, parent id is %d\n",getpid(),getppid());
	}

	return 0;
}
