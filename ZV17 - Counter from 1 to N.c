/*
Napiši program koji ispisuje sve prirodne brojeve od 1-N.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("%d\n", i);
    }

    return 0;
}
