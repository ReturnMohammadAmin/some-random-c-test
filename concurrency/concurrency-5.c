#include <pthread.h>
#include <stdlib.h>

struct Data {
    int val;
};

void* thread1(void* arg) {
    struct Data* d = (struct Data*)arg;
    d->val = 42;
    return NULL;
}

void* thread2(void* arg) {
    struct Data* d = (struct Data*)arg;
    d->val = 99;
    return NULL;
}

int main() {
    struct Data* shared = malloc(sizeof(struct Data));
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread1, shared);
    pthread_create(&t2, NULL, thread2, shared);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    free(shared);
    return 0;
}
