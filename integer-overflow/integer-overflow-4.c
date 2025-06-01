#include <stdio.h>
#include <limits.h>

int deep_add(int x, int depth) {
    if (depth == 0) return x;
    return deep_add(x + 1, depth - 1);
}

int main() {
    int x = INT_MAX - 5;
    int y = deep_add(x, 10);
    printf("%d\n", y);
    return 0;
}
