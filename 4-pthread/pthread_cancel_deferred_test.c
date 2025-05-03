#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *task(void* arg){
    printf("thread started\n");

    printf("working......\n");
    sleep(1);
    printf("before cancel check\n");
    pthread_testcancel();
    printf("after canceled\n");

    return NULL;
}

int main(){
    pthread_t tid;
    void *res;

    pthread_create(&tid, NULL, task, NULL);

    if(pthread_cancel(tid) != 0){
        perror("pthread_cancel");
    }

    pthread_join(tid, &res);

    if(res == PTHREAD_CANCELED){
        printf("thread was canceled\n");
    }else{
        printf("thread was not canceled, exit code: %ld\n",(long)res);
    }
    return 0;
}