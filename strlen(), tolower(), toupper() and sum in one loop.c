/*
Napiši program koji će ispisati duljinu određenog znakovnog niza, pretvoriti sva
mala slova u velika, a velika u mala, te izračunati i ispisati sumu znamenaka u
tom nizu.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_ZNAKOVA 100
#include <stdio.h>

int main()
{
	char string[MAX_ZNAKOVA];
	int counter = 0, zbroj = 0;

	scanf("%s", &string);

	for (int i = 0; i < MAX_ZNAKOVA; i++) {
		if (string[i] > 0 && string[i] <= 127)
			counter++;
		if (string[i] >= 'A' && string[i] <= 'Z')
			string[i] = string[i] + 32;
		else if (string[i] >= 'a' && string[i] <= 'z')
			string[i] = string[i] - 32;
		if (string[i] >= '0' && string[i] <= '9') {
			zbroj += ((int)string[i] - 48); // 48 je decimalna vrijednost za '0' u ASCII tablici pa ju oduzimamo
		}
	}

	printf("\nDuljina niza: %d\nZamjena slova: %s\nZbroj znamenki u nizu: %d", counter, string, zbroj);

	return 0;
}
