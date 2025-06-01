#include <pthread.h>
#include <stdio.h>

int flag = 0;
int shared = 0;

void* thread1(void* arg) {
    if (flag)
        shared = 1;
    return NULL;
}

void* thread2(void* arg) {
    flag = 1;
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
