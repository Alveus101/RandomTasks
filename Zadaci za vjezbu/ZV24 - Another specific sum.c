/*
Učitati prirodni broj N, a izračunati i ispisati sumu po sljedećem pravilu.
S = 1 + 1/2 + 3 + 1/4 + 5 + ...
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	float suma = 1;
	
	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) {
			suma += 1.0 / i;
		}
		else suma += i;
	}

	printf("%.2f", suma);

	return 0;
}
