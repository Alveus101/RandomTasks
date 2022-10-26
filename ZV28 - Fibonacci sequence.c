/*
Napisati program koji ispisuje N članova fibbonacijevog niza. Program treba
osigurati da je uneseni N u intervalu <2,21>.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int n, broj = 1, prviPrethodniBroj = 0, drugiPrethodniBroj = 1;

	scanf("%d", &n);

	if (n > 2 && n < 21) {

		printf("%d\n%d\n", prviPrethodniBroj, drugiPrethodniBroj);
		for (int i = 0; i < n; i++) {
			
			broj = prviPrethodniBroj + drugiPrethodniBroj;
			printf("%d\n", broj);

			prviPrethodniBroj = drugiPrethodniBroj;
			drugiPrethodniBroj = broj;
		}
	}
	
	return 0;
}
