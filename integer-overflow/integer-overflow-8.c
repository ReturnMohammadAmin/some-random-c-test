#include <stdio.h>

int main() {
    int x = scanf("%d", &x);
    x = x % 1000000;
    x = x * (x % 777) * (x % 888);
    printf("%d", x);
}