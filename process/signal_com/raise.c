#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>

int main(void)
{
	printf("raise before\n");
	raise(9);//给当前进程自己发送9信号	
	printf("raise before\n");
	
	return 0;
}
