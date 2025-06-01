#include <stdio.h>
#include <limits.h>

int main() {
    int sum = 0;
    for (int i = 0; i < INT_MAX; i++) {
        sum += i;
        if (sum < 0)
            break;
    }
    printf("%d\n", sum);
    return 0;
}
