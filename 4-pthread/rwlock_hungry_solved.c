#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


// static pthread_rwlock_t  rwlock = __PTHREAD_RWLOCK_INITIALIZER;
pthread_rwlock_t  rwlock;
int shared_data = 0;


void * lock_read(void * arg){

    // 读写锁中的读是可以由多个线程统一读取的
    // 获取读锁
    printf("我%s要获取读锁\n",(char *)arg);
    pthread_rwlock_rdlock(&rwlock);
    printf("当前是%s,shared_date为%d\n",(char *)arg,shared_data);
    sleep(1);
    pthread_rwlock_unlock(&rwlock);
    printf("我%s释放读锁\n",(char *)arg);
}

void * lock_writer(void * arg){
    // 给多个线程写入添加写锁  
    // 同一时间只能由一个线程获取写锁  会造成两个线程顺序执行
    printf("我%s要获取写锁\n",(char *)arg);
    pthread_rwlock_wrlock(&rwlock);
    int tmp = shared_data + 1;

    shared_data = tmp;
    printf("当前是%s,shared_date为%d\n",(char *)arg,shared_data);
    // 写入完成之后释放写锁
    pthread_rwlock_unlock(&rwlock);
    printf("我%s释放写锁\n",(char *)arg);
}

int main(int argc, char const *argv[])
{
    // 创建读写锁属性对象
    pthread_rwlockattr_t attr;
    pthread_rwlockattr_init(&attr);
    // 修改参数 设置写优先
    pthread_rwlockattr_setkind_np(&attr,PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP);
    // 显示初始化读写锁
    pthread_rwlock_init(&rwlock,&attr);

    pthread_t writer1,writer2,reader1,reader2,reader3,reader4,reader5,reader6;

    // 创建两个写线程
    pthread_create(&writer1,NULL,lock_writer,"writer1");
    // 休眠等待
    pthread_create(&reader1,NULL,lock_read,"reader1");
    pthread_create(&reader2,NULL,lock_read,"reader2");
    pthread_create(&reader3,NULL,lock_read,"reader3");
    // 在线程读取数据的时候  中间添加一个获取写锁的写操作
    pthread_create(&writer2,NULL,lock_writer,"writer2");
    pthread_create(&reader4,NULL,lock_read,"reader4");
    pthread_create(&reader5,NULL,lock_read,"reader5");
    pthread_create(&reader6,NULL,lock_read,"reader6");

    // 主线程等待创建的子线程运行完成
    pthread_join(writer1,NULL);
    pthread_join(writer2,NULL);
    pthread_join(reader1,NULL);
    pthread_join(reader2,NULL);
    pthread_join(reader3,NULL);
    pthread_join(reader4,NULL);
    pthread_join(reader5,NULL);
    pthread_join(reader6,NULL);

    // 销毁读写锁
    pthread_rwlock_destroy(&rwlock);
    return 0;
}
