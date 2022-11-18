/*
Napiši program koji će, nakon što učita sve element cjelobrojne matrice 4x4
ispisati pojedine sume svakog retka i pojedine sume svakog stupca matrice.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_REDAKA 4
#define MAX_STUPACA 4
#include <stdio.h>

int main()
{
	int matrica[MAX_REDAKA][MAX_STUPACA]{}, sumaRedaka[MAX_REDAKA]{}, sumaStupaca[MAX_STUPACA]{};

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
			sumaRedaka[i] += matrica[i][j];
		}
		printf(" |\n");
	}

	for (int i = 0; i < MAX_STUPACA; i++) {
		for (int j = 0; j < MAX_REDAKA; j++) {
			sumaStupaca[i] += matrica[j][i];
		}
	}

	for (int i = 0; i < MAX_REDAKA; i++) {
		printf("Suma %d. retka: %d\n", i+1, sumaRedaka[i]);
	}
	for (int i = 0; i < MAX_STUPACA; i++) {
		printf("Suma %d. stupca: %d\n", i + 1, sumaStupaca[i]);
	}

	return 0;
}
