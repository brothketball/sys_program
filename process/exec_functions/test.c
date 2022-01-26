#include<stdio.h>
#include<unistd.h>

int main(void)
{
	pid_t pid;
	int i = 0;
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

	// 子进程
	if(pid == 0)
	{
		printf("This is child, chhild id is %d, parent id is %d\n",getpid(),getppid());
	}

	i++;
	printf("i is %d\n",i);

	return 0;
}
