/*
Napiši program koji za cjelobrojno polje n[50] ispisuje koliko elemenata sadrži
parne, a koliko neparne vrijednosti. Prethodno je potrebno učitati sve elemente
polja.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 5
#include <stdio.h>

int main()
{
    int n[MAX], parniBrojevi = 0, neparniBrojevi = 0;

    for (int i = 0; i < MAX; i++) {
        scanf("%d", &n[i]);

        if (n[i] % 2 == 0) {
            parniBrojevi++;
        }
        else neparniBrojevi++;

    }

    printf("U nizu je %d parnih vrijednosti i %d neparnih vrijednosti.", parniBrojevi, neparniBrojevi);

    return 0;

}
