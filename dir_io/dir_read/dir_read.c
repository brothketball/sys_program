#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{
	int ret;
	DIR *dp;

	struct dirent *dir;

	if(argc != 2)
	{
		printf("Usage:%s <name dir>\n",argv[0]);
		return -1;
	}

	dp = opendir(argv[1]);

	if(dp == NULL)
	{
		printf("opendir is error!\n");
		return -2;
	}

	printf("opendir is ok\n");


	while(1)
	{
		dir = readdir(dp);
		if(dir != NULL)
		{
			printf("filename is %s\n",dir->d_name);
		}
		else
		{
			break;
		}
		
	}

	closedir(dp);

	return 0;
}
