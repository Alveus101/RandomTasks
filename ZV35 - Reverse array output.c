/*
Učitati N brojeva (maks. 100), te ih ispisati obrnutim redoslijedom.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h>

int main()
{
    int niz[MAX], i = 0;

    while (i < MAX) {
        scanf("%d", &niz[i]);
        i++;
    }

    printf("\nObrnuti redoslijed:\n");

    for (i -= 1; i >= 0; i--) {
        printf("%d\n", niz[i]);
    }

    return 0;

}
