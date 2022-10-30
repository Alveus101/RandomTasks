/*
Učitati prirodan broj n, te ispisati koliko i koji elementi cjelobrojnog polja
p[100] sadrže tu vrijednost. Prethodno je potrebno učitati elemente polja p.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include <stdio.h>

int main()
{
    int n, p[MAX], kolicina = 0;

    scanf("%d", &n);

    for (int i = 0; i < MAX; i++) {
        scanf("%d", &p[i]);
    }

    printf("\nRezultati se nalaze na sljedecim indeksima: ");

    for (int i = 0; i < MAX; i++) {
        if (p[i] == n) {
            printf("%d,", i);
            kolicina++;
        }
    }

    printf("\nPronadjeno je %d rezultata.", kolicina);

    return 0;

}
