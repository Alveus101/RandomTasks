/*
Zadatak: https://github.com/Alveus101/RandomTasks/blob/main/Other/Auditorne%206%20-%20Rijecnik.pdf
File: https://github.com/Alveus101/RandomTasks/blob/main/Other/Rjecnik.txt
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_WORD 30
#define MAX_DESC 100
#define MAX_STRING 200
#define PRIJEVODI 12

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct prijevod {
	char word[MAX_WORD];
	char desc[MAX_DESC];
};

void obradaTexta(char* word, char* desc, char* string, char* input) {
	char *p = strstr(desc, input), *token;
	char rijeci[30][MAX_WORD]{ {""} };
	int i = 0;

	strcpy(string, "");

	sprintf(string, "%s:", word);

	token = strtok(desc, " ");

	while (token != NULL) {
		
		strcat(rijeci[i], token);
		token = strtok(NULL, " ");
		i++;
	}

	for (int j = 0; j < i; j++) {
		
		if (strcmp(rijeci[j], input) == 0) {
			if (j >= 2)
				sprintf(string, "%s ... %s %s", string, rijeci[j - 2], rijeci[j - 1]);
			else if( j == 1 )
				sprintf(string, "%s %s", string, rijeci[j - 1]);
			
			sprintf(string, "%s %s", string, _strupr(rijeci[j]) );
			
			if (j + 3 <= i)
				sprintf(string, "%s %s %s ...", string, rijeci[j + 1], rijeci[j + 2]);
			else if (j + 2 < i)
				sprintf(string, "%s %s %s", string, rijeci[j + 1], rijeci[j + 2]);
		}
	}
}

int main() {
	char input[MAX_WORD], string[MAX_STRING] = "";
	FILE *fprijevod = NULL, *frjecnik = NULL;
	prijevod p[PRIJEVODI];
	int i = 0, found = 0;

	scanf("%s", input);

	frjecnik = fopen("Rjecnik.txt", "r");
	fprijevod = fopen("Prijevod.txt", "w");

	for (int i = 0; i < PRIJEVODI; i++) {
		fscanf(frjecnik, "\n%[^:]: %[^\n]", p[i].word, p[i].desc);
		
		if (strstr(p[i].desc, input) != NULL) {
			obradaTexta(p[i].word, p[i].desc, string, input);
			
			printf("%s\n", string);
			fprintf(fprijevod, "%s\n", string);
			
			found = 1;
		}
	}

	if (!found) {
		printf("NE POSTOJI RIJEC!");
		fprintf(fprijevod, "NE POSTOJI RIJEC!");
	}

	fclose(fprijevod);
	fclose(frjecnik);

	return 0;
}
