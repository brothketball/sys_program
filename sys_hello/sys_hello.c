#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	//main 输入来自命令行
	//argc 表示的是命令行中的参数个数
	//agrv 表示的是命令行中的参数
	
	printf("hello world!\n");

	//自身的可执行文件也算一个参数
	printf("argc is %d",argc);

	return 0;
}
