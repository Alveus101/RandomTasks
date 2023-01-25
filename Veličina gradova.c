/*
Zadatak: https://github.com/Alveus101/RandomTasks/blob/main/Other/Kolokvij%202_%20Zadatak%202%20-%20Veli%C4%8Dina%20gradova.PDF
File: https://github.com/Alveus101/RandomTasks/blob/main/Other/Gradovi.txt
*/
#define _CRT_SECURE_NO_WARNINGS
#define GRADOVI 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct grad {
	char drzava[20];
	char ime[20];
	int stanovnici;
	float povrsina;
	int glavni;
};

void sortiraj(grad* g, int found[GRADOVI], int fc, FILE* fout) {

	int temp = 0;

	for (int i = fc - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (g[found[j]].stanovnici < g[found[j + 1]].stanovnici) {
				temp = found[j];
				found[j] = found[j + 1];
				found[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < fc; i++)
		fprintf(fout,"%s ima %d stanovnika.\n", g[found[i]].ime, g[found[i]].stanovnici);	
}

int main() {

	FILE* fin = NULL, *fout = NULL;
	grad g[GRADOVI]{"","",0,0.0,0};
	int i = 0, found[GRADOVI], fc = 0, ukupnoStanovnika = 0;
	char input[20];

	fin = fopen("Gradovi.txt", "r");
	fout = fopen("Rezultati.txt", "w");

	while (fscanf(fin, "%s%s%d%f%d", g[i].drzava, g[i].ime, &g[i].stanovnici, &g[i].povrsina, &g[i].glavni) > 0)
		i++;

	scanf("%s", input);

	for (int j = 0; j < i; j++) {
		if (strcmp(input, g[j].drzava) == 0) {
			found[fc] = j;
			fc++;
			ukupnoStanovnika += g[j].stanovnici;
		}
	}

	if (fc == 0) fprintf(fout, "Nema podataka.");
	else {
		fprintf(fout, "%s ima ukupno: %d stanovnika.\n", input, ukupnoStanovnika);
		sortiraj(g, found, fc, fout);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
