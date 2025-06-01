#include <stdio.h>

int main() {
    int x = scanf("%d", &x);
    x = x % 20;
    x += (x % 3) * 10;
    x = 1 << x;
    printf("%d", x);
}