/*
Napiši program koji će pomoću samo jedne for petlje ispisati sve prirodne
brojeve od 1-N, a potom brojeve od N-1 do 1. Npr. za n=4 program ispisuje 1 2 3
4 3 2 1.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    int n, reverse = 0;

    scanf("%d", &n);

    if (n < 1) {
        printf("%d nije prirodni broj!", n);
        return 0;
    }

    for (int i = 1; i < n*2; i++) {
        
        if (i < n) printf("%d\n", i);
        else if (i == n) {
            reverse = n;
            printf("%d\n", n);
        }
        if (i > n) {
            reverse--;
            printf("%d\n", reverse);
        }
    }

    return 0;
}
