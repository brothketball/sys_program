wait函数
头文件：#include<sys/wait.h>
函数原型：pid_t wait (int *status)
返回值：成功返回回收的子进程的pid，失败返回-1
wait函数为阻塞函数，会使父进程进入阻塞态，直到子进程资源被回收

与wait函数参数相关的两个宏定义：
WIFEXITED(status)：如果子进程正常退出，则该宏定义为真
WEXITSTATUS(status)：如果子进程正常退出，则该宏定义的值为子进程的退出值，即exit()的参数
