#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<unistd.h>

int main(void)
{
	pid_t pid;
	int fd[2];

	char buf[32] = {0};

	//两个进程对同一个管道进行读写，所以需要在fork函数之前创造pipe
	pipe(fd);

	printf("fd[0] is %d\n",fd[0]);
	printf("fd[1] is %d\n",fd[1]);

	pid = fork();

	if(pid < 0)
	{
		printf("fork is error!\n");
		return -1;
	}

	// 父进程
	if(pid > 0)
	{
		//若父进程进入阻塞态，不写数据，则会无输出，卡住
		int status;

		//父进程现在只写不读，所以关闭读端
		close(fd[0]);
		write(fd[1],"hello",5);
		close(fd[1]);
		wait(&status);
		exit(0);
	}

	// 子进程
	if(pid == 0)
	{
		//子进程现在只读不写，所以关闭写端
		close(fd[1]);
		read(fd[0],buf,32);
		printf("buf is %s\n",buf);
		close(fd[0]);
		exit(0);
	}

	return 0;
}
