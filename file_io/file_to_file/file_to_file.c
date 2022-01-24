#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>


int main(int argc,char *argv[])
{
	//判断命令行中的参数个数
	if(argc != 3)
	{
		printf("Usage:%s <src file> <obj file>\n",argv[0]);
		return -1;
	}

	//定义变量
	int fd_src,fd_obj;
	char buf[32]={0};
	ssize_t ret;

	//打开文件，获得文件描述符
	fd_src = open(argv[1],O_RDWR);
	if(fd_src < 0)
	{
		printf("open is error!\n");
		return -1;
	}

	fd_obj = open(argv[2],O_CREAT|O_RDWR,0666);
	if(fd_src < 0)
	{
		printf("open is error!\n");
		return -1;
	}

	//读写操作
	while((ret = read(fd_src,buf,32))!=0)
	{
		write(fd_obj,buf,ret);
	}

	//关闭文件描述符
	close(fd_src);
	close(fd_obj);

	return 0;
}
