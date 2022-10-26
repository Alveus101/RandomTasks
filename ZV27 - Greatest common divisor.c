/*
Napiši program koji će pronaći i ispisati najveći zajednički djelitelj tri cijela
broja. Brojeve je potrebno učitati, te ispisati traženi rezultat.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int prviBroj, drugiBroj, treciBroj, maxDjeljitelj;

	scanf("%d%d%d", &prviBroj, &drugiBroj, &treciBroj);

	for (int i = 1; i <= prviBroj && i <= drugiBroj && i <= treciBroj; ++i) {
		if (prviBroj % i == 0 && drugiBroj % i == 0 && treciBroj % i == 0) {
			maxDjeljitelj = i;
		}
	}

	printf("%d", maxDjeljitelj);

	return 0;
}
