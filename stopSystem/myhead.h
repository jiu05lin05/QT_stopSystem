#ifndef _MYHEAD_H
#define _MYHEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <linux/input.h>  //跟输入子系统模型有关的头文件
#include <dirent.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <signal.h> //跟信号有关的头文件
#include <sys/shm.h> //跟共享内存有关的头文件
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h> //跟信号量有关的头文件
#include <pthread.h> //跟线程有关的头文件
#include <semaphore.h> //跟POSIX无名信号量有关的头文件
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <linux/videodev2.h> //跟V4L2有关的头文件
#endif
