//使用fork创建的子进程与父进程程序相同
//使用exec函数族可以创建程序不同的子进程
#include<stdio.h>
#include<stdlib.h>
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
		execl("/home/pi/Gits/sys_program/process/exec_functions/hello","hello",NULL);
		//execl将子进程程序换为指定文件hello
		exit(1);
	}

	i++;
	printf("i is %d\n",i);

	return 0;
}
