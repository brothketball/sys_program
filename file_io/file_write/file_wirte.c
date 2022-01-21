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
	
	write(fd,"Hello!\n",7);
	write(1,"Hello!\n",7);

	close(fd);

	return 0;
}
