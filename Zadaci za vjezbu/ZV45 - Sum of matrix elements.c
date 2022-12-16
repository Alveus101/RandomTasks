/*
Napiši program koji učitava elemente cjelobrojne kvadratne matrice 3x3, te
ispisuje sumu svih elemenata te matrice.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_REDAKA 3
#define MAX_STUPACA 3
#include <stdio.h>

int main()
{
	int matrica[MAX_REDAKA][MAX_STUPACA]{}, suma = 0;

	for (int i = 0; i < MAX_REDAKA; i++) {
		for (int j = 0; j < MAX_STUPACA; j++) {
			printf("Unesi vrijednost u %d. retku i %d. stupcu. (a%d%d) -> ", i+1, j+1, i+1, j+1);
			scanf("%d", &matrica[i][j]);
		}
	}

	printf("\nIzgled matrice:\n");

	for (int i = 0; i < MAX_REDAKA; i++) {
		printf("| ");
		for (int j = 0; j < MAX_STUPACA; j++) {
			printf("%d ", matrica[i][j]);
			suma += matrica[i][j];
		}
		printf(" |\n");
	}
	printf("Suma svih elemenata: %d", suma);
	return 0;
}
