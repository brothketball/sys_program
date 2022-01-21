#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int fd;
	int close_flag;
	fd = open("a.c",O_CREAT|O_RDWR,0666);
	if(fd < 0)
	{
		printf("open is error\n");
	}

	printf("fd is %d\n",fd);
	close_flag = close(fd);
	if(close_flag==0) printf("file is closed\n");
	else if(close_flag==-1) printf("file is failed to be closed successfully\n");
	return 0;
}
