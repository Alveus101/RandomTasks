#define _CRT_SECURE_NO_WARNINGS

#define MAX_R 50
#define MAX_S 50
#define TRUE 1
#define FALSE 0
#define DESNO 1
#define LIJEVO 2
#define DOLJE 3
#define GORE 4

#define PROLAZ				'.'
#define HRANA				'h'
#define PREPREKA			'x'
#define PUT_HORIZONTALNO		'-'
#define PUT_VERTIKALNO			'|'
#define PUT_SKRETANJE			'+'
#define UKOP				'*'
#define RUB				-52

#include <stdio.h>
#include <stdlib.h>

int korakNaprijed(char matrica[MAX_R][MAX_S], int* lokacija, int* psmjer) {

	int r = *(lokacija), s = *(lokacija + 1), smjer = *(psmjer), putDoHrane1 = 0, putDoHrane2 = 0, imaLiHraneUopce1 = FALSE, imaLiHraneUopce2 = FALSE;
	char staJeIspred = 'a';

	if (smjer == DESNO)
		staJeIspred = matrica[r][s + 1];

	else if (smjer == LIJEVO)
		staJeIspred = matrica[r][s - 1];

	else if (smjer == DOLJE)
		staJeIspred = matrica[r + 1][s];

	else if (smjer == GORE)
		staJeIspred = matrica[r - 1][s];

	if (staJeIspred == PROLAZ || staJeIspred == HRANA) {

		if (smjer == DESNO || smjer == LIJEVO) matrica[r][s] = PUT_HORIZONTALNO;
		else if (smjer == DOLJE || smjer == GORE) matrica[r][s] = PUT_VERTIKALNO;

		if (smjer == DESNO) *(lokacija + 1) = s + 1;
		else if (smjer == LIJEVO) *(lokacija + 1) = s - 1;
		else if (smjer == DOLJE) *(lokacija) = r + 1;
		else if (smjer == GORE) *(lokacija) = r - 1;

		return 1;
	}

	else if (staJeIspred == PREPREKA || (int)staJeIspred == RUB) {

		matrica[r][s] = PUT_SKRETANJE;

		if (smjer == DESNO || smjer == LIJEVO) {

			// Provjera smjera DOLJE
			for (int i = r; i < MAX_R;) {
				if (matrica[i + 1][s] == '.') {
					putDoHrane1++;
					i++;
				}
				else if (matrica[i + 1][s] == 'h') {
					imaLiHraneUopce1 = TRUE;
					putDoHrane1++;
					break;
				}
				else break;
			}

			// Provjera smjera GORE
			for (int i = r; i >= 0;) {
				if (matrica[i - 1][s] == '.') {
					putDoHrane2++;
					i--;
				}
				else if (matrica[i - 1][s] == 'h') {
					imaLiHraneUopce2 = TRUE;
					putDoHrane2++;
					break;
				}
				else break;
			}

			// Odredjivanje smjera
			if (imaLiHraneUopce2 && putDoHrane1 > putDoHrane2) *(psmjer) = GORE;
			else if (imaLiHraneUopce1 && putDoHrane1 < putDoHrane2) *(psmjer) = DOLJE;
			else if (putDoHrane1 > 0) *(psmjer) = DOLJE;
			else if (putDoHrane2 > 0) *(psmjer) = GORE;
			else {
				matrica[r][s] = UKOP;
				return 0;
			}

			// Update lokacije
			smjer = *(psmjer);

			if (smjer == DESNO) *(lokacija + 1) = s + 1;
			else if (smjer == LIJEVO) *(lokacija + 1) = s - 1;
			else if (smjer == DOLJE) *(lokacija) = r + 1;
			else if (smjer == GORE) *(lokacija) = r - 1;

		}
		else if (smjer == GORE || smjer == DOLJE) {

			// Provjera smjera DESNO
			for (int i = s; i < MAX_R;) {
				if (matrica[r][i + 1] == '.') {
					putDoHrane1++;
					i++;
				}
				else if (matrica[r][i + 1] == 'h') {
					imaLiHraneUopce1 = TRUE;
					putDoHrane1++;
					break;
				}
				else break;
			}

			// Provjera smjera LIJEVO
			for (int i = s; i >= 0;) {
				if (matrica[r][i - 1] == '.') {
					putDoHrane2++;
					i--;
				}
				else if (matrica[r][i - 1] == 'h') {
					imaLiHraneUopce2 = TRUE;
					putDoHrane2++;
					break;
				}
				else break;
			}

			// Odredjivanje smjera
			if (imaLiHraneUopce2 && putDoHrane1 > putDoHrane2) *(psmjer) = LIJEVO;
			else if (imaLiHraneUopce1 && putDoHrane1 < putDoHrane2) *(psmjer) = DESNO;
			else if (putDoHrane1 > 0) *(psmjer) = DESNO;
			else if (putDoHrane2 > 0) *(psmjer) = LIJEVO;
			else {
				matrica[r][s] = UKOP;
				return 0;
			}

			// Update lokacije
			smjer = *(psmjer);

			if (smjer == DESNO) *(lokacija + 1) = s + 1;
			else if (smjer == LIJEVO) *(lokacija + 1) = s - 1;
			else if (smjer == DOLJE) *(lokacija) = r + 1;
			else if (smjer == GORE) *(lokacija) = r - 1;
		}

		return 1;
	}

	else if (staJeIspred == PUT_HORIZONTALNO || staJeIspred == PUT_VERTIKALNO || staJeIspred == PUT_SKRETANJE) {
		matrica[r][s] = UKOP;
		return 0;
	}

	else {
		matrica[r][s] = PUT_SKRETANJE;
		return 1;
	}
}

int main() {

	int redovi, stupci, smjer = DESNO, mozeDalje = TRUE;
	int* psmjer = &smjer;
	int* lokacija = NULL;
	lokacija = (int*)calloc(2, sizeof(int));
	char matrica[MAX_R][MAX_S];

	scanf("%d", &redovi);
	scanf("%d", &stupci);

	for (int red = 0; red < redovi; red++) {
		for (int stupac = 0; stupac < stupci; stupac++)
			scanf(" %c", &matrica[red][stupac]);
	}

	while (mozeDalje)
		mozeDalje = korakNaprijed(matrica, lokacija, psmjer);

	for (int red = 0; red < redovi; red++) {
		for (int stupac = 0; stupac < stupci; stupac++)
			printf("%c", matrica[red][stupac]);
		printf("\n");
	}
	
	return 0;
}
