/*
Zadatak: https://github.com/Alveus101/RandomTasks/blob/main/Other/Kolokvij%20-%20Ciklicki%20zarotirani.pdf
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>

int pretvori(int broj, int baza) {
	int result = 0, znamenka = 0, ostatak = 0, counter = 0, j = 0;
	char ostaci[20] = "", noviBroj[20] = "";

	while (broj != 0) {

		ostatak = broj % baza;
		broj = broj / baza;
		
		ostaci[counter] = (char)ostatak+'0';
		counter++;
	}

	ostaci[counter] = '\0';
	counter = 0;

	printf("%s\n", _strrev(ostaci));

	for (int i = strlen(ostaci)-1; i > 0; i--) {
		if (ostaci[i] != (char)baza - 1 + '0') {
			noviBroj[j] = ostaci[i];
			j++;
		}
	}

	noviBroj[j] = '\0';
	strcpy(noviBroj, _strrev(noviBroj));

	printf("%s\n", noviBroj);

	while (counter < strlen(noviBroj)) {
		znamenka = (int)noviBroj[counter] - '0';
		result += znamenka * pow( baza, strlen(noviBroj) - counter - 1);
		counter++;
	}

	return result;
}

int main() {
	int broj = 0, baza = 0;

	scanf("%d", &broj);
	scanf("%d", &baza);

	printf("%d", pretvori(broj, baza));

	return 0;
}

