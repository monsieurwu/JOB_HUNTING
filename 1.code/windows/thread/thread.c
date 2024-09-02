#include <stdio.h>
#include <stdlib.h>
#include <process.h>

void thread_1_func(void* arg) {
    int i;
    int times = *((int*)arg);

    for(i = 0; i <= times; ++i) {
        printf("thread 1 process at %d times\n", i);
    }
    _endthread();
}

void thread_2_func(void* arg) {
    int i;
    int times = *((int*)arg);

    for(i = 0; i <= times; ++i) {
        printf("thread 2 process at %d times\n", i);
    }
    _endthread();
}


int thread1_times = 5;
int thread2_times = 10;

int main() {
    uintptr_t thread1, thread2;
    thread1 = _beginthread(thread_1_func, 0, (void*)&thread1_times);
    thread2 = _beginthread(thread_2_func, 0, (void*)&thread2_times);
    if(thread1 == -1 || thread2 == -1) {
        printf("create thread failed\n");
        return -1;
    }
    _endthread();
    return 0;
}