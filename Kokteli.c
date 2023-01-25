/*
Zadatak: https://github.com/Alveus101/RandomTasks/blob/main/Other/Kokteli.png
File: https://github.com/Alveus101/RandomTasks/blob/main/Other/kokteli.dat
*/
#define _CRT_SECURE_NO_WARNINGS
#define STRING 20+1
#define KOKTELI 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct koktel {
	char ime[STRING];
	float kolicinaPrvog;
	char prviSastojak[STRING];
	float kolicinaDrugog;
	char drugiSastojak[STRING];
	float kolicinaTreceg;
	char treciSastojak[STRING];
};

void sortiraj(koktel* k, int found[KOKTELI], int fc, FILE* fout) {

	int temp = 0;
	for (int i = fc - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (strcmp(k[found[j]].ime, k[found[j + 1]].ime) < 0) {
				temp = found[j];
				found[j] = found[j + 1];
				found[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < fc; i++)
		fprintf(fout, "%s (%s, %s, %s)\n", k[found[i]].ime, k[found[i]].prviSastojak, k[found[i]].drugiSastojak, k[found[i]].treciSastojak);
}

int main() {

	FILE* fin = NULL, * fout = NULL;
	koktel k[KOKTELI]{"",0.0,"",0.0,"",0.0,""};
	int i = 0, found[KOKTELI], fc = 0;
	char input[STRING];

	fin = fopen("kokteli.dat", "rb");
	fout = fopen("opcije.txt", "w");
	
	while (!feof(fin)) {
		fread(&k[i], sizeof(koktel), 1, fin);
		i++;
	}

	scanf("%[^\n]", input);

	for (int j = 0; j < i; j++) {
		if (strcmp(k[j].prviSastojak, input) != 0 && strcmp(k[j].drugiSastojak, input) != 0 && strcmp(k[j].treciSastojak, input) != 0 && strlen(k[j].prviSastojak) > 0) {
			found[fc] = j;
			fc++;
		}
	}

	sortiraj(k, found, fc, fout);

	fclose(fin);
	fclose(fout);
	return 0;
}
