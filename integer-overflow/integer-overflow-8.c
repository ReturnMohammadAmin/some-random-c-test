#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = rand();
    x = x % 1000000;
    x = x * (x % 777) * (x % 888);
    printf("%d", x);
}