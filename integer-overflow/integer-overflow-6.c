#include <stdio.h>
#include <limits.h>

int main() {
    int a = INT_MAX / 3, b = INT_MAX / 3, sum = 0;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            sum += (i + j) % 2;
}
