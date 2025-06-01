#include <stdio.h>
#include <limits.h>

typedef void (*func_ptr)(int*);

void add_hundred(int *x) {
    *x += 100;
}

void call_func(func_ptr f, int *val) {
    f(val);
}

int main() {
    int a = INT_MAX;
    func_ptr f = &add_hundred;
    call_func(f, &a);
    printf("%d\n", a);
    return 0;
}
