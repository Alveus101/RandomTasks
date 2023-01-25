/*
Zadatak: https://github.com/Alveus101/RandomTasks/blob/main/Other/Kolokvij%202-%20Zadatak%201%20-%20Swapper.pdf
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_INPUT 10
#define MAX_OUTPUT 20

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* rotate(char* a, char* b) {
	char output[MAX_OUTPUT] = "", parnaSlova[MAX_OUTPUT/2], neparnaSlova[MAX_OUTPUT/2];
	int j = 0, k = 0;

	_strrev(b);

	strcat(output, b);
	strcat(output, a);

	for (int i = 0; i < strlen(output); i++) {
		if (i % 2 == 0) {
			neparnaSlova[k] = output[i];
			k++;
		}
		else {
			parnaSlova[j] = output[i];
			j++;
		}
	}

	parnaSlova[j] = '\0';
	neparnaSlova[k] = '\0';

	strcpy(output, neparnaSlova);
	strcat(output, parnaSlova);

	return output;
}

int main() {

	char prvi[MAX_INPUT], drugi[MAX_INPUT];

	scanf("%[^\n]", prvi);
	scanf("\n%[^\n]", drugi);

	printf("%s", rotate(prvi, drugi));

	return 0;
}
