#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

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
		int status;
		wait(&status);
		if(WIFEXITED(status) == 1)
		{
			printf("return value is %d\n",WEXITSTATUS(status));
		}
	}

	// 子进程
	if(pid == 0)
	{
		sleep(2);
		printf("This is child\n");
		exit(6);
	}

	return 0;
}
