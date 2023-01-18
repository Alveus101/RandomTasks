/*
Zadatak: https://github.com/Alveus101/RandomTasks/blob/main/Other/Lab%2010_%20Zadatak%20na%20Vje%C5%BEbi%20-%20Letovi%20za%20Rim.pdf
File sa letovima: https://github.com/Alveus101/RandomTasks/blob/main/Other/Letovi.dat
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

int Rim(let* l, int brojLetova, int * najranijiLet, int * najkasnijiLet) {

	int letoviZaRim = 0, vrijemeSekunde = 0, najranijeVrijeme = 999999, najkasnijeVrijeme = 0;
	
	for (int i = 0; i < brojLetova; i++) {
		if (strcmp("Rome", l[i].odrediste) == 0) {
			letoviZaRim++;

			vrijemeSekunde = l[i].polazakS * 3600;
			vrijemeSekunde += l[i].polazakM * 60;

			if (vrijemeSekunde < najranijeVrijeme) {
				najranijeVrijeme = vrijemeSekunde;
				*(najranijiLet) = i;
			}
			if (vrijemeSekunde > najkasnijeVrijeme) {
				najkasnijeVrijeme = vrijemeSekunde;
				*(najkasnijiLet) = i;
			}
		}
	}
	return letoviZaRim;
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
	char time[6] = "", najranijiTime[6] = "", najkasnijiTime[6] = "";
	int i = 0, cntRead = 1, brojLetova = 0, najranijiLet = 0, najkasnijiLet = 0;

	getchar();

	file = fopen("Letovi.dat", "rb");

	while (cntRead == 1) {
		cntRead = fread(&l[i], sizeof(let), 1, file);
		i++;
	}

	brojLetova = Rim(l, i, &najranijiLet, &najkasnijiLet);

	strcat(najranijiTime, formatTime(time, l[najranijiLet].polazakS, l[najranijiLet].polazakM));
	strcat(najkasnijiTime, formatTime(time, l[najkasnijiLet].polazakS, l[najkasnijiLet].polazakM));

	printf("Za Rim ima %d letova\nNajraniji: %s|%s|%s\nNajkasniji: %s|%s|%s",
		brojLetova,
		l[najranijiLet].polaziste, l[najranijiLet].odrediste, najranijiTime,
		l[najkasnijiLet].polaziste, l[najkasnijiLet].odrediste, najkasnijiTime
	);

	fclose(file);
	return 0;
}
