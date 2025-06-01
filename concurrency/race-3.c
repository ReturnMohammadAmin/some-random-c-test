#include <pthread.h>
#include <stdio.h>
#include <assert.h>

int a = 0, b = 0;

void* thread1(void* arg) {
    b = 1;
    for (int i = 0; i < rand() % 10000; i++);
    a = 1;
    return NULL;
}

void* thread2(void* arg) {
    if (b == 1 && a == 0) {
        printf("Atomicity violated\n");
        assert(0);
    }
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
