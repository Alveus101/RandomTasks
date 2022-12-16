/*
Napiši program koji će izračunati sumu svih parnih brojeva od M-N. (M<N)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    int m, n, suma=0;

    scanf("%d%d", &m, &n);

    if (m > n) return 0;

    for (int i = m; i < n; i++) {
        if (i % 2 == 0) {
            suma += i;
        }
    }

    printf("%d", suma);

    return 0;
}
