/*
Napiši program koji će učitati N brojeva i ispisati najmanji i najveći broj, te na kojem se mjestu unosa nalaze.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    int kolicina, broj, min = 0, max = 0, minPlace, maxPlace;

    scanf("%d", &kolicina);

    for (int i = 1; i <= kolicina; i++) {
        scanf("%d", &broj );
        
        if (i == 1) {
            min = broj;
            max = broj;
            minPlace = i;
            maxPlace = i;
        }
        if (broj > max) {
            max = broj;
            maxPlace = i;
        }
        if (broj < min) {
            min = broj;
            minPlace = i;
        }

    }

    printf("Minimum: %d na %d. mjestu.\nMaximum: %d na %d. mjestu.", min, minPlace, max, maxPlace);

    return 0;
}
