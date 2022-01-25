#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>


int main(int argc,char *argv[])
{
	//定义变量
	int fd_src,fd_obj;
	char buf[32]={0};
	char file_path[32]={0};
	char file_name[32]={0};
	ssize_t ret;
	DIR *dp;
	struct dirent *dir;

	//键盘输入文件路径
	printf("Please enter the file path:\n");
	scanf("%s",file_path);

	//打开目录，并获取目录流指针，然后读取目录打印文件名
	dp = opendir(file_path);
	
	if(dp==NULL)
	{
		printf("opendir is error!\n");
		return -1;
	}
		
	printf("opendir is ok\n");

	while(1)
	{
		dir = readdir(dp);

		if(dir != NULL)
		{
			printf("file name is %s\n",dir->d_name);
		}
		else
		{
			break;
		}
	}

	//获得要复制的文件的文件名
	printf("Please enter the file name:\n");
	scanf("%s",file_name);


	//获得文件描述符
	fd_src = open(strcat(strcat(file_path,"/"),file_name),O_RDWR);
	if(fd_src < 0)
	{
		printf("open is error!\n");
		return -1;
	}

	fd_obj = open(file_name,O_CREAT|O_RDWR,0666);
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
	closedir(dp);

	return 0;
}
