#include <stdlib.h>

void fill(char *p, int n) {
    for (int i = 0; i < n; ++i)
        p[i] = 'A';
}

int main() {
    char *buf = (char *)malloc(16);
    int n = 32;
    fill(buf, n);
    free(buf);
    return 0;
}
