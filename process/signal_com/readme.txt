								信号发送
kill函数：
#include<sys/types.h>
#include<signal.h>
int kill(pid_t pid,int sig);
//同理kill命令

raise函数：
#include<signal.h>
int raise(int sig);
//等同于kill(getpid(),sig);，即给当前进程自己发信号

alarm函数：
#include<unistd.h>
unsigned int alarm(unsigned int seconds);
//定时产生SIGALRM信号，该信号默认操作为终止

								信号接收
while、sleep函数：
可以使进程不断运行，直到接收到停止信号，即Ctrl+c，对应SIGINT信号

pause函数：
#include<unistd.h>
int pause(void);
//该函数会令当前进程暂停(进入睡眠状态)，直到被信号所中断
//返回值只有-1

想要接收信号，则需要进程不能停止

								信号处理
信号处理的三种方式：系统默认、忽略、捕获

signal函数：
#include<signal.h>
typedef void(*sighandler_t)(int);
sighandler_t signal(int signum,sighandler_t handler);
//可简化成：
//signal(参数1，参数2);
//参数1：我们要进行处理的信号，可通过kill -l查看
//参数2：处理的方式(是系统默认还是忽略还是捕获)

1)signal(SIGINT,SIG_IGN);
  SIG_IGN代表忽略，也就是忽略SIGINT信号
2)signal(SIGINT,SIG_DFL);
  SIG_DFL代表执行系统默认操作，大多数默认为终止
3)signal(SIGINT,myfun);
  捕捉SIGINT这个信号，然后执行myfun函数里面自定义的代码
