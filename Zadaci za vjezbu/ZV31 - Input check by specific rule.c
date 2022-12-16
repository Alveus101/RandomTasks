/*
Napisati program koji će učitavati cijele brojeve s tipkovnice i postupati prema
sljedećem pravilu: ako je učitani broj manji od nule treba ispisati poruku o
grešci i prestati sa učitavanjem brojeva. Ako je učitani broj veći od 100 treba ga
zanemariti i prijeći na sljedeći broj, a inače ga treba ispisati. Prestati sa
učitavanjem kada se učita 0.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int broj = 1;

	while (broj != 0) {
		scanf("%d", &broj);

		if (broj < 0) {
			printf("Greska: broj je manji od 0.");
			return 0;
		}
		else if (broj > 100)
			continue;
		else if (broj != 0)
			printf("%d\n", broj);
	}
	
	return 0;
}
