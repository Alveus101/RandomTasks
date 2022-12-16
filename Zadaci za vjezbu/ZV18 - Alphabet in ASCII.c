/*
Napiši program koji će za sva mala i velika slova engleske abecede ispisati
njihove ASCII vrijednosti.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    for (char c = 'A'; c <= 'Z'; c++) {
        printf("%c - %d\n", c, c);
    }
    for (char c = 'a'; c <= 'z'; c++) {
        printf("%c - %d\n", c, c);
    }
    return 0;
}
