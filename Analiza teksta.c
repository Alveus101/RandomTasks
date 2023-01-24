/*
Zadatak: https://github.com/Alveus101/RandomTasks/blob/main/Other/Auditorne%206%20-%20Analiza%20teksta.pdf
File: https://github.com/Alveus101/RandomTasks/blob/main/Other/Sentiment.txt
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_INPUT 100
#define MAX_WORD 20
#define MAX_EMOTION 4
#define SENTIMENTI 35

#include <stdio.h>
#include <string.h>

struct sentiment {
	char word[MAX_WORD];
	char emotion[MAX_EMOTION];
};

int main() {

	FILE *fin = NULL, *fout = NULL;
	sentiment s[SENTIMENTI];
	char input[MAX_INPUT], *found = NULL;
	int i = 0, pozCount = 0, negCount = 0;

	scanf("%[^\n]", input);

	fin = fopen("Sentiment.txt", "r");
	fout = fopen("RezultatAnalize.txt", "w");

	while (!feof(fin)) {
		fscanf(fin, "%[^:]: %[^\n]\n", s[i].word, s[i].emotion);
		i++;
	}

	fprintf(fout, "%s\n", input);

	found = strtok(input, " ");
	while ( 1 ) {
		found = strtok(NULL, " ");
		if (found == NULL) break;
		
		for (int j = 0; j < i; j++) {
			if (strstr(found, s[j].word) != NULL) {
				if (strcmp(s[j].emotion, "POZ") == 0) pozCount++;
				else if (strcmp(s[j].emotion, "NEG") == 0) negCount++;
				fprintf(fout, "%s\n", s[j].word);
				break;
			}
		}
	}

	if (pozCount > negCount) fprintf(fout, "Analiza: pozitivna");
	else if (pozCount < negCount) fprintf(fout, "Analiza: negativna");
	else fprintf(fout,"Analiza: neutralna");

	fclose(fin);
	fclose(fout);
	return 0;
}
