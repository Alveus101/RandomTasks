/*
Napiši program koji unosi maksimalno 10 znakovnih nizova maksimalne duljine
100 znakova. Program treba ispisati nizove u obrnutom redoslijedu znakova.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_STRINGOVA 10
#define MAX_ZNAKOVA 100
#include <stdio.h>

int main()
{
	char string[MAX_STRINGOVA][MAX_ZNAKOVA];
	int charCount[MAX_STRINGOVA]{};

	for (int i = 0; i < MAX_STRINGOVA; i++) {
		
		gets_s(string[i]);
		
		for (int j = 0; j < MAX_ZNAKOVA; j++) {
			if ((int)string[i][j] >= 0 && (int)string[i][j] <= 127)
				charCount[i]++;
		}
	}
		
	for (int i = 0; i < MAX_STRINGOVA; i++) {
		for (int j = charCount[i]-1; j >= 0; j--) {
			printf("%c", string[i][j]);
		}
		printf("\n");
	}

	return 0;
}
