/*
Zadatak: https://github.com/Alveus101/RandomTasks/blob/main/Other/Kolokvij%202%20Zadatak%201%20-%20ASCII%20maker.pdf
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_RECENICA 100
#define MAX_RIJEC 20

#include <stdio.h>
#include <string.h>

int zbroji(char recenica[MAX_RECENICA], char* najveca) {
	int zbroj = 0, maxZbroj = 0, i = 1;
	char* rijeci[10];

	recenica[strlen(recenica) - 1] = '\0';

	rijeci[0] = strtok(recenica, " ");

	while( 1 ){
		rijeci[i] = strtok(NULL, " ");
		if (rijeci[i] == NULL) break;
		else i++;
	}

	for (int j = 0; j < i; j++) {
		for (int k = 0; k < strlen(rijeci[j]); k++) {
			
			zbroj += (int)rijeci[j][k];
			
			if (zbroj > maxZbroj) {
				maxZbroj = zbroj;
				strcpy(najveca, rijeci[j]);
			}
		}
		zbroj = 0;
	}

	return maxZbroj;
}

int main() {
	char recenica[MAX_RECENICA];
	char najvecaRijec[MAX_RIJEC];
	
	scanf("%[^\n]", recenica);

	int zbroj = zbroji(recenica, najvecaRijec);
	printf("%s: %d", najvecaRijec, zbroj);

	return 0;
}
