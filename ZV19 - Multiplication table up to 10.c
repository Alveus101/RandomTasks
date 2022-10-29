/*
Napiši program koji će ispisati tablicu množenja do 10
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    int umnozak;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            umnozak = i * j;
            printf("%d * %d = %d\n", i, j, umnozak);
        }
    }

    return 0;
}
