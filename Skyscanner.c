#define _CRT_SECURE_NO_WARNINGS
#define MAX_INPUT 4+1
#define MAX_LETOVA 2000

#include <stdio.h>
#include <string.h>

struct let {
	char broj[9 + 1];
	char polazniA[4 + 1];
	char dolazniA[4 + 1];
	char datum[15 + 1];
	char vrijeme[5 + 1];
	float cijena;
	char trajanje[5 + 1];
};

int pretvoriUSekunde(char trajanje[5 + 1]) {
	int sekunde = 0;

	// Pretvorba sati u sekunde
	if (trajanje[0] > '0' && trajanje[0] <= '9')
		sekunde += ( (int)trajanje[0] - (int)'0' ) * 10 * 3600;
	if (trajanje[1] > '0' && trajanje[1] <= '9') 
		sekunde += ((int)trajanje[1] - (int)'0') * 3600;
	
	// Pretvorba minuta u sekunde
	if (trajanje[3] > '0' && trajanje[3] <= '9')
		sekunde += ((int)trajanje[3] - (int)'0') * 10 * 60;
	if (trajanje[4] > '0' && trajanje[4] <= '9')
		sekunde += ((int)trajanje[4] - (int)'0') * 60;

	return sekunde;
}

void zamjeniMjesta(int index, int dest, let * l) {
	let temp = { "", "", "", "", "", 0.0, 0, 0 };

	temp = l[dest];
	l[dest] = l[index];
	l[index] = temp;
}

int main() {
	
	FILE *file = NULL, *fout = NULL;
	struct let l[MAX_LETOVA] = { "", "", "", "", "", 0.0, 0, 0 };
	struct let output[MAX_LETOVA] = { "", "", "", "", "", 0.0, 0, 0 };
	char inputP[MAX_INPUT], inputD[MAX_INPUT];
	int i = 0, found = 0;

	scanf("%[^-]-%s", inputP, inputD);

	file = fopen("letovi.txt", "r");
	fout = fopen("Rezultat.txt", "w");

	while (!feof(file)) {
		fscanf(file, "%s %[^-]-%s%s%s%f%s", l[i].broj, l[i].polazniA, l[i].dolazniA, l[i].datum, l[i].vrijeme, &l[i].cijena, l[i].trajanje);
		i++;
	}

	// Sort
	for (int b = i - 1; b > 0; b--) {
		for (int a = 0; a < b; a++) {
			if (pretvoriUSekunde(l[a].trajanje) < pretvoriUSekunde(l[a+1].trajanje))
				zamjeniMjesta(a + 1, a, l);
		}
	}

	// Ispis & zapis u file
	for (int j = 0; j < i; j++) {
		if (strcmp(inputP, l[j].polazniA) == 0 && strcmp(inputD, l[j].dolazniA) == 0) {
			printf("%s-%s %s %s %s\n", l[j].polazniA, l[j].dolazniA, l[j].datum, l[j].vrijeme, l[j].trajanje);
			fprintf(fout, "%s-%s %s %s %s\n", l[j].polazniA, l[j].dolazniA, l[j].datum, l[j].vrijeme, l[j].trajanje);
			found++;
		}
	}

	if (found == 0) {
		printf("NE POSTOJI LET!");
		fprintf(fout, "NE POSTOJI LET!");
	}

	fclose(file);
	fclose(fout);

	return 0;
}
