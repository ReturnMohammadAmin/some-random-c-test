#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = rand();
    x = x % 20;
    x += (x % 3) * 10;
    x = 1 << x;
    printf("%d", x);
}