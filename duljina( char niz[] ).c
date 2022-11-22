/*
Napiši funkciju koja vraća duljinu zadanog niza znakova. Prototip funkcije glasi:
int duljina(char niz[]);
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_SLOVA 10
#include <stdio.h>

int duljina(char niz[]) {
	int counter = 0;

	for (int i = 0; i < MAX_SLOVA; i++) {
		if (niz[i] > 0 )
			counter++;
	}	

	return counter;
}

int main() {
	
	char niz[MAX_SLOVA]{};

	gets_s(niz);

	printf("%d", duljina(niz));

	return 0;
}
