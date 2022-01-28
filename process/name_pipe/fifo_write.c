#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int ret;
	int fd;

	if(argc < 2)
	{
		printf("Usage:%s <fifo name>\n",argv[0]);
		return -1;
	}
	
	//access函数用于判断是否存在这样的一个文件
	//F_OK：是否存在
	//R_OK、W_OK、X_OK：是否可读、可写、可执行
	if(access(argv[1],F_OK) == -1)
	{
		ret = mkfifo(argv[1],0666);
		if(ret == -1)
		{
			printf("mkfifo is error\n");
			return -2;
		}
		printf("mkfifo is ok\n");
	}

	fd = open(argv[1],O_WRONLY);

	while(1)
	{
		sleep(1);
		write(fd,"hello",5);
	}

	close(fd);

	return 0;
}
