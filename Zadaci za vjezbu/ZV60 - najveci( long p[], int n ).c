/*
Napiši funkciju koja vraća vrijednost najvećeg elementa u polju. Prototip
funkcije glasi:
long najveci(long p[], int n);
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include <stdio.h>

long najveci(long p[], int n) { // ne kuzim koji kurac ce mi n, al jbg takav prototip

	long najveci = 0;

	for (int i = 0; i < n; i++) {
		if (p[i] > najveci)
			najveci = p[i];
	}
	return najveci;
}


int main() {

	long niz[MAX], n = 0;

	for (int i = 0; i < MAX; i++) {
		scanf("%d", &niz[i]);
		n++;
	}

	printf("%ld", najveci(niz, n));

	return 0;
}
