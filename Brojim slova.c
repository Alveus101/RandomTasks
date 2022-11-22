/*Potrebno je unositi mala ili velika slova eng. abecede dok se ne unese *, 
i na kraju ispisati kojeg je slova koliko bilo. Primjerice, za unesena slova aAabfF, 
ispisuje se:
a: 3
b: 1
f: 2
Najvise je bilo slova a.*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_SLOVA 100
#include <stdio.h>

int main() {
	
	char unos = 0, slovo[MAX_SLOVA]{}, najcesceSlovo = 0;
	int kolicinaSlova[MAX_SLOVA]{}, maxSlovo = 0;

	do {
		scanf("%c", &unos);

		for (int i = 0; i < MAX_SLOVA; i++) {

			if ((int)unos == 10 || unos == '*') break;
			
			if (unos >= 'A' && unos <= 'Z') {
				unos = (int)unos + 32;
			}
			
			if (unos == slovo[i]) {
				kolicinaSlova[i]++;
				break;
			}

			else if (slovo[i] == 0) {
				slovo[i] = unos;
				kolicinaSlova[i]++;
				break;
			}
		}

	} while (unos != '*');

	for (int i = 0; i < MAX_SLOVA; i++) {
		
		if( slovo[i] != 0 )
			printf("%c:%d\n", slovo[i], kolicinaSlova[i]);
		
		if (kolicinaSlova[i] > maxSlovo) {
			maxSlovo = kolicinaSlova[i];
			najcesceSlovo = slovo[i];
		}
	}

	printf("Najvise je bilo slova %c.", najcesceSlovo);

	return 0;
}
