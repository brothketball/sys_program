#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int i;

	alarm(3);

	while(1)
	{
		sleep(1);
		i++;
		printf("i = %d\n",i);
	}

	return 0;
}
