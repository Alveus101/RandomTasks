/*
Napiši funkciju koja vraća broj samoglasnika koji se nalazi u nekom znakovnom
nizu. Prototip funkcije glasi:
int samoglasnik(char niz[]);
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_SLOVA 100
#include <stdio.h>

int samoglasnik(char niz[]) {
	int counter = 0;

	for (int i = 0; i < MAX_SLOVA; i++) {
		if (niz[i] == 'A' || niz[i] ==  'a' 
		 || niz[i] == 'E' || niz[i] == 'e' 
		 || niz[i] == 'I' || niz[i] == 'i'
		 || niz[i] == 'O' || niz[i] == 'o'
		 || niz[i] == 'U' || niz[i] == 'u')
			counter++;
	}	

	return counter;
}

int main() {
	
	char niz[MAX_SLOVA]{};

	gets_s(niz);

	printf("%d", samoglasnik(niz));

	return 0;
}
