#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int fd;
	fd = open("a.c",O_CREAT|O_RDWR,0666);
	if(fd < 0)
	{
		printf("open is error\n");
	}

	printf("fd is %d\n",fd);
	return 0;
}
