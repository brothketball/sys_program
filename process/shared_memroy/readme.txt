共享内存是进程间通信效率最高的一种方式，因为创建的共享内存可以通过shmat函数
将共享内存映射到用户空间的地址中，由此用户无需再次进入内核

shmget函数：
#include<sys/ipc.h>
#include<sys/shm.h>
int shmget(ket_t ket,size_t size,int shmflg);
参数：
key_t key：IPC_PRIVATE或者是ftok函数的返回值
size_t size：共享内存的大小
int shmflg：权限
			使用宏定义IPC_PRIVATE，直接写入权限值即可
			且对应的key值为0
			使用ftok函数返回值，则需要填写 权限值|IPC_CREAT
			且对应的key值不为0
返回值：成功返回共享内存的标识符，失败返回-1

ftok函数：
#include<sys/types.h>
#include<sys/ipc.h>
ket_t ftok(const char *pathname,int proj_id);
参数：
const char *pathname：文件路径以及文件名
int proj_id：字符
返回值：成功返回key值，失败返回-1

shmat函数：
#include<sys/types.h>
#include<sys/shm.h>
void *shmat(int shmid,const void *shmaddr,int shmflg);
参数：
int shmid：共享内存的标识符，也就算shmgtet函数的返回值
const void *shmaddr：映射到的地址，一般写NULL，表示系统自动完成映射
int shmflg：通常为0，表示共享内存可读可写，或者为SHM_RDONLY，表示共享内存只
读
返回值：成功返回共享内存映射到进程中的地址，失败返回-1

shmdt函数：
#include<sys/types.h>
#include<sys/shm.h>
int shmdt(const void *shmaddr);
参数：
const void *shmaddr：共享内存映射后的地址
返回值：成功返回0，失败返回-1
PS：shmdt函数是将进程中的地址映射删除，即当一个进程不不需要共享内存的时候，
就可以使用这个函数将他从进程地址空间中脱离，并不会删除内核里面的共享内存对象

shmctl函数：
#include<sys/ipc.h>
#include<sys/shm.h>
int shmctl(int shmid,int cmd,struct shmid_ds *buf);
参数：
int shmid：要操作的共享内存标识符
int cmd：IPC_STAT(获取对象属性)、IPC_SET(设置对象属性)、IPC_RMID(删除对象)
struct shmid_ds *buf：指定IPC_STAT(获取对象属性)、IPC_SET(设置对象属性)时用
来保存或者设置的属性
返回值：成功返回0，失败返回-1
