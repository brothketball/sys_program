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
	fd = open(argv[1],O_RDWR);
	if(fd < 0)
	{
		printf("open is error\n");
	}

	ret = lseek(fd,0,SEEK_END);
	printf("ret is %ld\n",ret);
	lseek(fd,0,SEEK_SET);

	read(fd,buf,ret);
	if(ret<0)
	{
		printf("read is error!\n");
		return -2;
	}
	
	printf("1st read:\n");
	printf("%s\n",buf);
	
	//指针指回文件开头
	lseek(fd,0,SEEK_SET);

	ret = read(fd,buf,32);
	printf("2nd read:\n");
	printf("%s\n",buf);

	close(fd);

	return 0;
}
