/*
Zadatak: https://github.com/Alveus101/RandomTasks/blob/main/Other/Parne%20i%20neparne%20rijeci.pdf
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STRING 10+1
#define MAX_RIJECI 20
#define MIN_RIJECI 1
#define MAX_RECENICA 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void razdvoji(int n, char** rijeci, char* neparna, char* parna) {

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			strcat(parna, rijeci[i]);
			strcat(parna, " ");
		}
		else {
			strcat(neparna, rijeci[i]);
			strcat(neparna, " ");
		}
	}

	parna[0] = toupper(parna[0]);
	neparna[0] = toupper(neparna[0]);

	if (strlen(parna) > 1) parna[strlen(parna)-1] = '.'; parna[strlen(parna)] = '\0';
	if( strlen(neparna) > 1 ) neparna[strlen(neparna)-1] = '.'; neparna[strlen(neparna)] = '\0';

}

int main() {
	int n = 0;
	char neparnaRecenica[MAX_RECENICA] = "", parnaRecenica[MAX_RECENICA] = "";
	
	while ( n < MIN_RIJECI || n > MAX_RIJECI)
		scanf("%d", &n);

	char** rijeci = (char**)calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++) rijeci[i] = (char*)calloc(MAX_STRING, sizeof(char));

	for( int i = 0; i < n; i++)
		scanf("\n%[^\n]", rijeci[i]);

	razdvoji(n, rijeci, neparnaRecenica, parnaRecenica);

	if( strlen(parnaRecenica) > 2 ) printf("%s", parnaRecenica);
	if( strlen(neparnaRecenica) > 2 ) printf("\n%s", neparnaRecenica);
	
	return 0;
}
