消息队列：创建、发送、接收

msgget函数：
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
int msgget(ket_t key,int msgflg);
参数：
key_t key：和消息队列相关的key值
int msgflg：访问权限
返回值：
成功返回消息队列的ID，失败返回-1


