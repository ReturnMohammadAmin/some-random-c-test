#include <pthread.h>
#include <stdio.h>

int x = 0;

void* thread1(void* arg) {
    for (int i = 0; i < 1e4; i++)
        x += 1;
    return NULL;
}

void* thread2(void* arg) {
    for (int i = 0; i < 1e4; i++)
        x += 2;
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
