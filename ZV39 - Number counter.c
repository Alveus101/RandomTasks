/*
Napiši program koji će učitati prirodan broj N, i isto toliko elemenata u
intervalu [1,100]. Program treba ispisati koliko puta je unesen svaki broj u
zadanom intervalu. Ukoliko se unese broj koji nije u zadanom intervalu treba ga
zanemariti.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h>

int main()
{
    int n, broj, niz[MAX+1]{}, kolicina = 0;

    scanf("%d", &n);

    if (n > MAX) {
        printf("N je veci od %d! Potrebno je podesiti MAX konstantu u kodu!", MAX);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &broj);

        if (broj >= 1 && broj <= 100) {
            niz[broj]++;
            kolicina++;
        }

    }

    for (int i = 0; i < MAX+1; i++) {
        if (niz[i] != 0) {
            printf("Broj %d je unesen %d puta.\n", i, niz[i]);
        }
    }

    printf("Uneseno je %d brojeva iz intervala [1,100]!", kolicina);

    return 0;
}
