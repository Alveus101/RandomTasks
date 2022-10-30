/*
Napiši program koji će u realnom polju p[25] sve elemente polja podijeliti sa
najmanjim elementom u polju. Prethodno je potrebno učitati elemente polja
p.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 25
#include <stdio.h>

int main()
{
    float p[MAX], najmanji = 0;

    for (int i = 0; i < MAX; i++) {
        scanf("%f", &p[i]);

        if (i == 0) 
            najmanji = p[i];
        
        if (p[i] < najmanji)
            najmanji = p[i];
    }

    for (int i = 0; i < MAX; i++) {
        printf("%.2f / %.2f = %.2f\n", p[i], najmanji, p[i] / najmanji);
    }

    return 0;
}
