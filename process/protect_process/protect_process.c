#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(void)
{
	pid_t pid;
	//创建一个新的子进程
	pid = fork();
	
	//直接退出父进程
	if(pid > 0)
	{
		exit(0);
	}


	if(pid == 0)
	{
		//摆脱控制终端
		setsid();
		
		//更改工作目录
		chdir("/");

		//重新设置umask
		umask(0);

		//关闭0、1、2三个文件描述符
		close(0);
		close(1);
		close(2);

		//执行我们想要执行的代码
		//该处使用死循环，需手动结束进程
		while(1);
	}

	return 0;
}
