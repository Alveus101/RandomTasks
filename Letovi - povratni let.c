/*
Zadatak: https://i.imgur.com/gx2OBMd.png
Letovi.dat file: https://github.com/Alveus101/RandomTasks/blob/main/Other/Letovi.dat
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_CITY_NAME 30+1
#define MAX_LETOVA 505

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct let {
	char polaziste[MAX_CITY_NAME];
	char odrediste[MAX_CITY_NAME];
	int polazakS;
	int polazakM;
	double cijena;
};

int pronadjiLet(char gradP[MAX_CITY_NAME], char gradO[MAX_CITY_NAME], let* l, int brojLetova, int* pp) {
	int letID = -1;
	double minCijena = 999999.99, ukupnaCijena = 0;

	// Trazenje direktnog leta
	for (int i = 0; i < brojLetova; i++) {
		if (strcmp(gradP, l[i].polaziste) == 0 && strcmp(gradO, l[i].odrediste) == 0) {
			if (l[i].cijena < minCijena) {
				letID = i;
				minCijena = l[i].cijena;
			}
		}
	}

	// Trazenje presjedanja
	for (int i = 0; i < brojLetova; i++) {
		if (strcmp(gradP, l[i].polaziste) == 0) {

			ukupnaCijena += l[i].cijena;

			for (int j = 0; j < brojLetova; j++) {
				if (strcmp(gradO, l[j].odrediste) == 0 && strcmp(l[i].odrediste, l[j].polaziste) == 0) {
					ukupnaCijena += l[j].cijena;
					if (ukupnaCijena < minCijena) {
						letID = i;
						*(pp) = j;
						minCijena = ukupnaCijena;
						ukupnaCijena = 0;
					}
				}
			}
			ukupnaCijena = 0;
		}
	}
	return letID;
}

char* formatTime(char* time, int hour, int min) {

	if (hour < 10 && min < 10)
		sprintf(time, "0%d:0%d", hour, min);
	else if (hour < 10 && min > 10)
		sprintf(time, "0%d:%d", hour, min);
	else if (hour > 10 && min < 10)
		sprintf(time, "%d:0%d", hour, min);
	else if (hour > 10 && min > 10)
		sprintf(time, "%d:%d", hour, min);

	return time;
}

int main() {

	FILE* file = NULL;
	let l[MAX_LETOVA] = { "","", 0, 0, 0.0 };
	char gradP[MAX_CITY_NAME], gradO[MAX_CITY_NAME], time[6] = "";
	int i = 0, cntRead = 1, letID = 0, presjedanjeID = -1;

	scanf("%[^-]-%[^\n]", gradP, gradO);

	file = fopen("Letovi.dat", "rb");

	while (cntRead == 1) {
		cntRead = fread(&l[i], sizeof(let), 1, file);
		i++;
	}

	letID = pronadjiLet(gradP, gradO, l, i, &presjedanjeID);

	if (presjedanjeID > -1)
		printf("%s - %s: %.2f\nPolazak u %s\nPresjedanje: %s", l[letID].polaziste, l[letID].odrediste, l[letID].cijena + l[presjedanjeID].cijena, formatTime(time, l[letID].polazakS, l[letID].polazakM), l[presjedanjeID].polaziste);

	else printf("%s - %s: %.2f\nPolazak u %s", l[letID].polaziste, l[letID].odrediste, l[letID].cijena, formatTime(time, l[letID].polazakS, l[letID].polazakM));

	letID = pronadjiLet(gradO, gradP, l, i, &presjedanjeID);

	if (presjedanjeID > -1)
		printf("\n%s - %s: %.2f\nPolazak u %s\nPresjedanje: %s", l[letID].polaziste, gradP, l[letID].cijena + l[presjedanjeID].cijena, formatTime(time, l[letID].polazakS, l[letID].polazakM), l[presjedanjeID].polaziste);

	else printf("\n%s - %s: %.2f\nPolazak u %s", l[letID].polaziste, gradP, l[letID].cijena, formatTime(time, l[letID].polazakS, l[letID].polazakM));

	fclose(file);
	return 0;
}
