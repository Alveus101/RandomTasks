/*
Napiši program koji će učitati broj stupaca i broj redaka neke realne matrice.
Matrica je realizirana pomoću 1D polja, a program za nju treba zauzeti
potrebnu količinu memorije. Matricu je potrebno ispisati nakon što se popuni
popuniti slučajnim (random) vrijednostima u intervalu [1,9]
*/

#define _CRT_SECURE_NO_WARNINGS
#define RAND_MIN 1
#define RAND_MAXX 9

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int stupci, redci;
	int* matrica = NULL;

	scanf("%d", &stupci);
	scanf("%d", &redci);

	matrica = (int*)malloc(redci * stupci * sizeof(int));

	for (int i = 0; i < redci; i++) {
		for (int j = 0; j < stupci; j++) {
			if( matrica )
				*(matrica+i*stupci+j) = rand() % RAND_MAXX + RAND_MIN;
		}
	}

	for (int i = 0; i < redci; i++) {
		for (int j = 0; j < stupci; j++) {
			if( matrica )
				printf("%d ", *(matrica+i*stupci+j));
		}
		printf("\n");
	}

	return 0;
}
