#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>

union semun{
	int val;
};

int main(void)
{
	int semid;
	int key;
	pid_t pid;
	union semun semun_union;
	struct sembuf sem;

	key = ftok("./a.c",0666);

	semid = semget(key,1,0666|IPC_CREAT);

	//初始化信号量
	semun_union.val = 0;
	semctl(semid,0,SETVAL,semun_union);

	pid = fork();

	//信号量值初始化为0，父进程先执行P操作，进入阻塞态，直到子进程进行V操作
	if(pid > 0)
	{
		sem.sem_num = 0;
		sem.sem_op = -1;
		sem.sem_flg = 0;
		semop(semid,&sem,1);
		printf("This is parents\n");
		sem.sem_num = 0;
		sem.sem_op = 1;
		sem.sem_flg = 0;
		semop(semid,&sem,1);
	}

	if(pid == 0)
	{
		sleep(1);
		sem.sem_num = 0;
		sem.sem_op = 1;
		sem.sem_flg = 0;
		semop(semid,&sem,1);
		printf("This is son\n");
	}


	return 0;
}
