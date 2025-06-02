#include <stdio.h>
#include <stdlib.h>

int add(int x, int y) {
    return x + y;
}

int main() {
    int a, b;
    a = rand();
    b = rand();
    scanf("%d %d", &a, &b);
    int result = add(a, b);
    printf("%d\n", result);
    return 0;
}
