#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void myfun(int sig)
{
	if(sig == SIGINT)
	{
		printf("get signal\n");
	}
}

void main(void)
{
	//signal(SIGINT,SIG_DFL);//对2号信号(Ctrl+c)进行默认系统操作
	//signal(SIGINT,SIG_IGN);//对2号信号(Ctrl+c)进行忽略操作
	signal(SIGINT,myfun);//对2号信号(Ctrl+c)进行自定义myfun操作
	
	while(1)
	{
		printf("wait signal...\n");
		sleep(1);
	}
}
