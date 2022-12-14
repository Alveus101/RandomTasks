/*
Učitati prirodni broj N, a izračunati i ispisati sumu po sljedećem pravilu.
S = 1 + 1/2 + 1/3 + 1/4 + ... + 1/N
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	float suma = 1;
	
	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		suma += (1.0 / i);
	}

	printf("%.2f", suma);

	return 0;
}
