/*
Napiši program koji radi isti posao kao i funkcija strcmpi. Ta funkcija
uspoređuje 2 znakovna niza, zanemarujući razliku između velikih i malih slova.
Program treba ispisati da li se znakovni nizovi razlikuju.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_ZNAKOVA 100
#include <stdio.h>

int main()
{
	char prviString[MAX_ZNAKOVA], drugiString[MAX_ZNAKOVA];
	int counter = 0;

	scanf("%s", &prviString);
	scanf("%s", &drugiString);

	// Zamjena velikih slova malim slovima
	for (int i = 'A'; i <= 'Z'; i++) {
		for (int j = 0; j < MAX_ZNAKOVA; j++) {
			if (prviString[j] == i) {
				prviString[j] = (int)prviString[j] + 32;
			}
			if (drugiString[j] == i) {
				drugiString[j] = (int)drugiString[j] + 32;
			}
		}
	}
	// ------------------------------------

	for (int i = 0; i < MAX_ZNAKOVA; i++) {
		if (prviString[i] != drugiString[i]) {
			counter++;
		}
	}

	if (counter == 0) {
		printf("Znakovni nizovi se NE razlikuju.");
	}
	else
		printf("Znakovni nizovi se razlikuju.");

	return 0;
}
