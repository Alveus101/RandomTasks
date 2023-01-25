/*
Zadatak: https://github.com/Alveus101/RandomTasks/blob/main/Other/Kolokvij%20-%20Drzave%20-%20Ruralno%20stanovnistvo.pdf
File: https://github.com/Alveus101/RandomTasks/blob/main/Other/stanovnistvo.dat
*/

#define _CRT_SECURE_NO_WARNINGS
#define DRZAVE 50

#include <stdio.h>
#include <string.h>

struct drzava {
	char ime[20 + 1];
	float stanovnici;
	int g_stanovnici;
	float postotak;
};

void sortiraj(drzava* d, int found[DRZAVE], int fc, FILE* fout) {
	int temp;

	for (int i = fc - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (d[found[j]].g_stanovnici > d[found[j + 1]].g_stanovnici) {
				temp = found[j];
				found[j] = found[j + 1];
				found[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < fc; i++) {
		fprintf(fout, "%s#%.2f#%d\n", d[found[i]].ime, d[found[i]].stanovnici, d[found[i]].g_stanovnici);
	}
}

int main() {
	
	FILE* fin = NULL, *fout = NULL;
	drzava d[DRZAVE]{ "",0.0,0,0.0 };
	int i = 0, p = 0, found[DRZAVE], fc = 0;
	float postotak = 0.0;

	fin = fopen("stanovnistvo.dat", "rb");
	fout = fopen("ruralne.txt", "w");

	while (!feof(fin)) {
		fread(&d[i], sizeof(drzava), 1, fin);
		i++;
	}

	scanf("%d", &p);

	for (int j = 0; j < i; j++) {
		if (d[j].g_stanovnici < p && d[j].g_stanovnici > 0) {
			found[fc] = j;
			fc++;
		}
	}

	if (fc == 0) fprintf(fout,"Nema takve drzave.");
	else sortiraj(d, found, fc, fout);

	fclose(fin);
	fclose(fout);

	return 0;
}
