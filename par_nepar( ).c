/*
Napisati program koji od korisnika traži unos N brojeva (N može poprimiti vrijednost između 1 i 20). 
U slučaju unosa broja N izvan raspona zatražiti ponovan unos broja N. Brojevi se zapisuju u jednodimenzionalno polje.

Nakon toga poziva se funkcija par_nepar kojoj se predaje polje brojeva. 
Funkcija provjerava da li su brojevi u polju parani ili neparani. 
Ispisuje koliko ima parnih, a koliko neparnih brojeva u polju.

U slučaju da ima više parnih brojeva, ponoviti cijeli postupak.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 20
#include <stdio.h>

int par_nepar( int polje[], int n );

int main() {
	int n = 0, polje[MAX];

	while (n < 1 || n > MAX) {
		scanf("%d", &n);
		if (n < 1 || n > MAX) printf("Ponovo unesite N!");
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &polje[i]);
	}

	par_nepar(polje, n);

	return 0;
}

int par_nepar(int polje[], int n) {

	int parni = 0, neparni = 0;

	for (int i = 0; i < n; i++) {
		if (polje[i] % 2 == 0) parni++;
		else neparni++;
	}

	printf("Parnih brojeva ima: %d\nNeparnih brojeva ima: %d", parni, neparni);

	if (parni > neparni) return main();

	return 0;
}
