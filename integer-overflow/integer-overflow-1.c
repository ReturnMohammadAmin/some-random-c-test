#include <stdio.h>

int add(int x, int y) {
    return x + y;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int result = add(a, b);
    printf("%d\n", result);
    return 0;
}
