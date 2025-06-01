#include <stdio.h>
#include <limits.h>

int main() {
    int a = INT_MAX, b = INT_MAX, sum = 0;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            sum += (i + j) % 2;
}
