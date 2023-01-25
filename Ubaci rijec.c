/*
Zadatak: https://github.com/Alveus101/RandomTasks/blob/main/Other/Kolokvij%202_%20Zadatak%201%20-%20Ubaci%20rijec.PDF
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 40
#define MAX_OUTPUT 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ubaci_string(char* string1, char* string2, int a) {
	int count = 0, brojac = 0, j = 0;
	char output[MAX_OUTPUT] = "";

	for (int i = 0; i < strlen(string1); i++) {
		if (brojac == a) {
			strcat(output, string2);
			brojac = 0;
			j = j + strlen(string2);
			count++;
		}
		output[j] = string1[i];
		j++;
		brojac++;
	}

	strcpy(string1, output);
	return count;
}

int main() {
	char str1[MAX_OUTPUT], str2[MAX];
	int a = 0;

	scanf("%[^\n]", str1);
	scanf("\n%[^\n]", str2);
	scanf("%d", &a);

	printf("Ubaceno: %d\n", ubaci_string(str1, str2, a));
	printf("%s", str1);

	return 0;
}
