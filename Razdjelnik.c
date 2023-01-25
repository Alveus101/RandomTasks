/*
Zadatak: https://github.com/Alveus101/RandomTasks/blob/main/Other/Razdjelnik.png
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void razdijeli(char* ulaz, char razdjelnik, char* prvi, char* drugi) {

	int j = 0, found = 0;

	for (int i = 0; i < strlen(ulaz); i++) {
		if (ulaz[i] == razdjelnik && found == 0) {
			found = 1;
			prvi[i] = '\0';
			continue;
		}
		if (found) {
			drugi[j] = ulaz[i];
			j++;
		}
		else prvi[i] = ulaz[i];
	}

	drugi[j] = '\0';
}

int main() {

	int length = 0;
	char razdjelnik, prvi[MAX], drugi[MAX];

	scanf("%d", &length);
	
	char* rijec = (char*)malloc(length*sizeof(char));

	scanf("\n%[^\n]", rijec);
	scanf("\n%c", &razdjelnik);

	razdijeli(rijec, razdjelnik, prvi, drugi);

	printf("%s %d\n%s %d", prvi, strlen(prvi), drugi, strlen(drugi));
	return 0;
}
