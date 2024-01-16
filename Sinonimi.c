/*
Zadatak:

U datoteci sinonimi.txt se nalazi popis riječi i njihovih sinonima, u obliku da se na početku linije nalazi pojam, zatim dvotočka te niz zarezom odvojenih sinonima (moguce je da neki sinonim ima dvije ili vise rijeci). Jedan zapis moze izgledati ovako:
lako: lagano, jednostavno, trivijalno, s lakocom

Nakon toga potrebno je ucitati rečenicu sa standardnog ulaza, te ispisati sve varijacije te rečenice na način da se prva riječ koja ima sinonim zamijeni svim mogućim sinonimima. Primjerice, za rečenicu:

Pero je lako.

Rezultat će biti:
Pero je lagano.
Pero je jednostavno.
Pero je trivijalno.
Pero je s lakocom.

Rezultat je potrebno ispisati u datoteku Kombinacije.txt.

Napomena: Ulazni podaci neće biti takvi da se u ulaznim podacima nalaze dvije riječi koje imaju sinonim (primjerice, neće biti ulaz Pero je lako, ali kamen nije lako dici). 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100
#define MAX_RIJEC 20
#define MAX_SINONIMI 100
#define MAX_S 40

struct sinonim{
	char rijec[MAX_RIJEC];
	char sinonimi[MAX_SINONIMI];
};

int main() {

	int i = 0, f_len = 0, imali = 0;
	char input[MAX_INPUT], cut[MAX_INPUT];
	char* found = NULL, *result = NULL;
	FILE* fin = NULL, * fout = NULL;
	struct sinonim s[MAX_S] = { "", "" };

	strcpy(input, "");
	strcpy(cut, "");

	scanf("%100[^\n]%*c", input);

	fin = fopen("sinonimi.txt", "r");
	fout = fopen("Kombinacije.txt", "w");
	
	while (!feof(fin)) {
		fscanf(fin, "\n%[^:]: %[^\n]", s[i].rijec, s[i].sinonimi);
		i++;
	}

	for (int j = 0; j < i-1; j++) {

		found = strstr(input, s[j].rijec);

		if (found) {

			f_len = strlen(found);
			strncpy(cut, input, strlen(input) - f_len);

			cut[ strlen(input) - f_len] = '\0';

			result = strtok(s[j].sinonimi, ",");
			while (result != NULL) {
				printf("%s%s.\n", cut, result);
				fprintf(fout, "%s%s.\n", cut, result);
				result = strtok(NULL, ",");
			}

			imali = 1;
		}
	}

	if (imali == 0) printf("NEMA SINONIMA.");

	return 0;
}
