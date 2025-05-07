#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

sem_t *full;
sem_t *empty;

int shard_num;

int rand_num(){
    srand(time(NULL));
    return rand();
}

void * producer(void * arg){
    for (size_t i = 0; i < 5; i++)
    {
        // 获取信号量
        // 最开始 empty为1  可以减1  正常执行
        // 下次再到这里 empty为0 不能减1  卡住
        // 
        sem_wait(empty);
        printf("\n第%d轮数据传输\n",i + 1);
        sleep(1);
        shard_num = rand_num();
        // 释放信号量
        // 使full + 1 此时 消费者就能够获取信号量
        sem_post(full);
    }
    
}

void * consumer(void * arg){
    for (size_t i = 0; i < 5; i++)
    {
        // 获取信号量
        // 最开始 full为0  不能减1  卡住
        sem_wait(full);
        printf("\n第%d轮消费者开始读取数据\n",i + 1);
        sleep(1);
        printf("接收到的数字是%d",shard_num);
        // 释放信号量
        // 消费者执行一轮 释放信号empty + 1  生产者就能获取信号量
        sem_post(empty);
    }
}

int main(int argc, char const *argv[])
{
    full = malloc(sizeof(sem_t));
    empty = malloc(sizeof(sem_t));

    // 初始化信号量
    sem_init(empty,0,1);
    sem_init(full,0,0);

    // 创建生产者和消费者的线程
    pthread_t producer_id,consumer_id;
    pthread_create(&producer_id,NULL,producer,NULL);
    pthread_create(&consumer_id,NULL,consumer,NULL);

    // 等待线程全部执行完成
    pthread_join(producer_id,NULL);
    pthread_join(consumer_id,NULL);

    // 代码最后摧毁信号量
    sem_destroy(empty);
    sem_destroy(full);

    return 0;
}
