/*Potrebno je unositi mala ili velika slova eng. abecede dok se ne unese *, 
i na kraju ispisati kojeg je slova koliko bilo. Primjerice, za unesena slova aAabfF, 
ispisuje se:
a: 3
b: 1
f: 2
Najvise je bilo slova a.*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_ASCII 128
#include <stdio.h>

int main() {
	
	char unos = 0;
	int kolicinaSlova[MAX_ASCII]{};

	do {
		scanf("%c", &unos);
		if (unos != '*') {
			if (unos >= 'A' && unos <= 'Z') {
				kolicinaSlova[(int)unos+32]++;
			}
			else kolicinaSlova[(int)unos]++;
		}

	} while (unos != '*');

	for (int i = 0; i < MAX_ASCII; i++) {
		if (kolicinaSlova[i] != 0 && i != 10) {
			printf("%c: %d\n", i, kolicinaSlova[i]);
		}
	}

	return 0;
}
