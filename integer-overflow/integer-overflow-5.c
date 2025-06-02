#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, sum = 0;
    a = rand();
    b = rand();
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b ; j++)
            sum += (i + j + 1) % 2;
    if (sum == 0xffffffff)
        assert(0);
}
