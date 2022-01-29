信号量不同于其他进程间通信，它的主要目的在于保护共享资源
其本质为计数器，当进程访问共享资源时，需要判断信号量的值，当其大于0时可以访
问，当其等于0时不可访问
信号量也处于内核当中

semget函数（获得信号量ID）：
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
int semget(key_t key,int nsems,int semflg);
参数：
key_t key：信号量的键值，通过ftok函数获取
int nsems：信号量的数量
int semflg：标识
返回值：
成功返回信号量的ID，失败返回-1


semctl函数：
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
int semget(int semid,int semnum,int cmd,union semun arg);
参数：
int semid：信号量的ID
int semnum：信号量编号
int cmd：IPC_STAT（获取信号量的属性)、IPC_SET（设置信号量的属性）、IPC_RMID（删除信号量）、SETVAL（设置信号量的值）
arg：union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *_buf;
}
返回值：
成功返回0，失败返回-1

semop函数（进行V/P操作，V为1，释放资源；P为-1，分配资源）：
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
int semget(int semid,struct sembuf *sops,size_t nsops);
参数：
int semid：信号量ID
struct sembuf *sops：信号量结构体数组
struct sembuf{
	unsigned short sem_num;//要操作的信号量的编号
	short sem_op;//V/P操作，0为等待，直到信号量值变成0
	short sem_flg;//0表示阻塞，IPC_NOWAIT表示非阻塞
}
size_t nsops 要操作信号量的数量
返回值：
成功返回0，失败返回-1
