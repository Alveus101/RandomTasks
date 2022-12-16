/*
Napisati program koji će tražiti unos niza brojeva (maks. 100), nakon čega će
izračunati aritmetičku sredinu tog niza, te najprije ispisati brojeve manje od
aritmetičke sredine, a zatim one koji su veći od aritmetičke sredine.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include <stdio.h>

int main()
{
    float niz[MAX], suma = 0.0, prosjek = 0.0;

    for (int i = 0; i < MAX; i++) {
        scanf("%f", &niz[i]);
        suma += niz[i];
    }

    prosjek = suma / MAX;
    printf("Aritmeticka sredina: %.2f\n", prosjek);

    printf("\nBrojevi manji od aritmeticke sredine:\n");

    for (int i = 0; i < MAX; i++) {
        if (niz[i] < prosjek) {
            printf("%.2f\n", niz[i]);
        }
    }

    printf("\nBrojevi veci od aritmeticke sredine:\n");

    for (int i = 0; i < MAX; i++) {
        if (niz[i] > prosjek) {
            printf("%.2f\n", niz[i]);
        }
    }

    return 0;
}
