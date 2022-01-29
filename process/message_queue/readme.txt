消息队列：创建、发送、接收

命令行:
查询消息队列：ipcs -q
删除消息队列：ipcrm -q <msqid>

msgget函数（创建）：
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
int msgget(ket_t key,int msgflg);
参数：
key_t key：和消息队列相关的key值
		   与内存共享同理，不使用宏定义，而使用ftok函数创建key时，权限值需要|IPC_CREAT
int msgflg：访问权限
消息队列是一个链式队列，所以无需传入大小参数
返回值：
成功返回消息队列的ID，失败返回-1

msgctl函数（删除）：
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
int msgctl(int msgid,int cmd,struct msqid_ds *buf);
参数：
int msqid：消息队列的ID
int cmd：IPC_STAT：读取消息队列的属性，然后保存在buf指向的缓冲区
		 IPC_SET：设置消息队列的属性，这个值取自buf参数
		 IPC_RMID：删除消息队列，此时buf参数为NULL
struct msqid_ds *buf：消息队列的缓冲区
返回值：
成功返回0，失败返回-1

msgsnd函数（发送）：
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
int msgsnd(int msgid,const void *msgp,size_t msgsz,int msgflg);
参数：
int msqid：消息队列的ID
const void *msgp：指向消息类型的指针
size_t msgsz：发送的消息的字节数
int msgflg：如果为0，直到发送完成函数才返回，即阻塞发送；如果为IPC_NOWAIT：
消息没有发送完成，函数也会返回，即非阻塞发送
返回值：
成功返回0，失败返回-1

消息结构体：
struct msgbuf{
	long mtype;//消息的类型，msgsnd函数中的第二个参数
	char mtext[1];//消息的内容，其大小是msgsnd函数中的第三参数
}

msgrcv函数（接收）：
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
size_t msgrcv(int msqid,void *msgp,size_t msgsz,long msgtype,int msgflg);
参数：
int msqid：消息队列的ID
void *msgp：接收消息的缓冲区
size_t msgsz：发送的消息的字节数
long msgtype：接收消息的标识，0代表接收消息队列中的第一个消息
int msgflg：如果为0，为阻塞读取；如果为IPC_NOWAIT，为非阻塞发送
返回值：
成功返回接收到的消息的长度，失败返回-1

ps:消息队列当中的消息内容被接收后会被自动清除，即发一次只能收一次
