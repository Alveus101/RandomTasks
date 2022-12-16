#define _CRT_SECURE_NO_WARNINGS

#define MAX_POLJE 10
#define MIN_POLJE 3

#define TRUE 1
#define FALSE 0

#include <stdio.h>

int main() {

	int visinaPolja, sirinaPolja, kolikoZnakova, krajIgre = FALSE, redak, stupac, counter = 0, nepravilanUnos = TRUE;
	char polje[MAX_POLJE][MAX_POLJE], tkoIgraSljedeci, pobjednik = '?';

	while (nepravilanUnos == TRUE) {
		scanf("%dx%d", &visinaPolja, &sirinaPolja);
		
		if (visinaPolja >= MIN_POLJE && visinaPolja <= MAX_POLJE && sirinaPolja >= MIN_POLJE && sirinaPolja <= MAX_POLJE)
			nepravilanUnos = FALSE;
		else printf("Nedozvoljena dimenzija polja!");
	}
		
	scanf("%d", &kolikoZnakova);
	scanf(" %c", &tkoIgraSljedeci);

	for (int i = 0; i < visinaPolja; i++) {
		for (int j = 0; j < sirinaPolja; j++) {
			polje[i][j] = '-';
		}
	}

	while (!krajIgre) {

		for (int i = 0; i < visinaPolja; i++) {
			for (int j = 0; j < sirinaPolja; j++) {
				printf("%2c", polje[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		if (pobjednik != '?') {
			printf("Pobjednik je igrac %c!", pobjednik);
			break;
		}
		
		for (int k = 0; k < 2; k++) {
			scanf("%d", &redak);
			scanf("%d", &stupac);

			polje[redak - 1][stupac - 1] = tkoIgraSljedeci;

			for (int i = 0; i < sirinaPolja; i++) {
				for (int j = 0; j < visinaPolja; j++) {
					if (polje[j][i] == tkoIgraSljedeci)
						counter++;
				}
				if (counter == kolikoZnakova) {
					if( pobjednik == '?' ) pobjednik = tkoIgraSljedeci;
					break;
				}
				counter = 0;
			}

			if (tkoIgraSljedeci == 'X') tkoIgraSljedeci = 'O';
			else if (tkoIgraSljedeci == 'O') tkoIgraSljedeci = 'X';
		}
	}

	return 0;
}
