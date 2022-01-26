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
		while(1);
	}

	// 子进程
	if(pid == 0)
	{
		printf("This is child");
		exit(0);
	}

	return 0;
}
