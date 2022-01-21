#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int fd;
	char buf[32]={0};
	ssize_t ret;
	fd = open("a.c",O_CREAT|O_RDWR,0666);
	if(fd < 0)
	{
		printf("open is error\n");
	}

	printf("fd is %d\n",fd);
	ret = read(fd,buf,32);
	if(ret<0)
	{
		printf("read is error!\n");
		return -2;
	}
	
	printf("ret is %ld\n",ret);
	printf("buf is %s\n",buf);

	//第二次读取时，指针指向文件末尾，所以返回的ret为0
	ret = read(fd,buf,32);
	printf("ret is %ld\n",ret);

	close(fd);

	return 0;
}
