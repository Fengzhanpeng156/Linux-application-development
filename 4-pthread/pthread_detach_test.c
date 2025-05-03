#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *task(void *arg){
    printf("THread started\n");
    sleep(2);
    printf("thread finished\n");
    return NULL;
}

int main(){
    // 创建一个线程
    pthread_t tid;

    // 创建一个线程，执行task函数
    pthread_create(&tid, NULL, task, NULL);

    // 分离线程，使线程结束后自动释放资源
    pthread_detach(tid);

    printf("Main thread continued\n");

    sleep(3);//等待子线程

    printf("Main thread ending\n");

    return 0;

}