/*
Napiši program koji će vršiti unos prirodnih brojeva sve dok se ne unese 0.
Program treba ispisati aritmetičku sredinu unesenih brojeva.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    int broj = 1, zbroj = 0, prosjek = 0, brojac = 0;

    while (broj != 0) {
        scanf("%d", &broj);

        if (broj < 0) {
            printf("%d nije prirodni broj!", broj);
            return 0;
        }

        if (broj != 0) brojac++;
        zbroj += broj;
        prosjek = zbroj / brojac;
    }

    printf("%d", prosjek);

    return 0;
}
