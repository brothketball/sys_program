#include<stdio.h>
#include<unistd.h>

void main(void)
{
	printf("pause before\n");
	pause();
	printf("pause after\n");
}
