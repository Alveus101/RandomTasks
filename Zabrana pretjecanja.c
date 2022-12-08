#define _CRT_SECURE_NO_WARNINGS
#define MAX 300

#define POMAK_K 1
#define POMAK_M 3
#define POMAK_A 2

#include <stdio.h>

void pomak(char niz[], int duzina, int vrijeme) {

	int pomak = 0;

	for (int i = 0; i < vrijeme; i++) {
		for (int j = duzina; j >= 0; j--) {
			
			if (niz[j] == 'K') {

				pomak = j + POMAK_K;

				if (pomak >= duzina) duzina += POMAK_K;
				else {
					while (niz[pomak] != '.')
						pomak--;
				}
				
				niz[pomak] = 'K';
				niz[j] = '.';
			}
			else if (niz[j] == 'A') {

				pomak = j + POMAK_A;

				if (pomak >= duzina) duzina += POMAK_A;
				else {
					while (niz[pomak] != '.')
						pomak--;
				}
				
				niz[pomak] = 'A';
				niz[j] = '.';
			}
			else if (niz[j] == 'M') {

				pomak = j + POMAK_M;

				if (pomak >= duzina) duzina += POMAK_M;
				else {
					while (niz[pomak] != '.')
						pomak--;
				}

				niz[pomak] = 'M';
				niz[j] = '.';
			}

		}
	}

	for (int i = 0; i < duzina; i++) {
		printf("%c", niz[i]);
	}
}

int main() {
	int duzina, vrijeme;
	char cesta[MAX];

	scanf("%d", &duzina);
	scanf("%d", &vrijeme);

	for (int i = 0; i < duzina; i++)
		scanf(" %c", &cesta[i]);
		
	pomak(cesta, duzina, vrijeme);
	
	return 0;
}
