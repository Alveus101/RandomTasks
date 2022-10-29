/*
Napiši program koji će za zadani N učitati toliki broj pozitivnih vrijednosti i na
kraju ispisati njihovu sumu. Ukoliko se unese negativan broj prestati daljnje
učitavanje i ispisati trenutnu sumu.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int n, broj, suma = 0;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &broj);

		if (broj < 0) {
			printf("Suma: %d", suma);
			return 0;
		}
		suma += broj;
	}

	printf("Suma: %d", suma);

	return 0;
}
