#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int count = 0;

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond_producer = PTHREAD_COND_INITIALIZER;  // 生产者等待“非满”
static pthread_cond_t cond_consumer = PTHREAD_COND_INITIALIZER;  // 消费者等待“非空”

void *producer(void *arg) {
    int item = 1;
    while (1) {
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE) {  // 缓冲区满，等待
            pthread_cond_wait(&cond_producer, &mutex);
        }
        buffer[count++] = item++;
        printf("Producer sent: %d\n", buffer[count-1]);
        pthread_cond_signal(&cond_consumer);  // 只唤醒消费者
        pthread_mutex_unlock(&mutex);
    }
}

void *consumer(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (count == 0) {  // 缓冲区空，等待
            pthread_cond_wait(&cond_consumer, &mutex);
        }
        printf("Consumer received: %d\n", buffer[--count]);
        pthread_cond_signal(&cond_producer);  // 只唤醒生产者
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    return 0;
}