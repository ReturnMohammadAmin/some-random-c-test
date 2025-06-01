#include <stdlib.h>
#include <stdio.h>

void fill(char *p, int n) {
    for (int i = 0; i < n; ++i)
        p[i] = 'A';
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    char *buf = (char *)malloc(m);
    fill(buf, n);
    free(buf);
    return 0;
}
