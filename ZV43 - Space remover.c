/*
Napiši program koji će učitati N (max. 10) znakovnih nizova duljine max. 50
znakova. Nakon unosa, program treba ispisati pojedine nizove tako da ignorira
razmake. Npr. za niz: "Ovo je primjer " program treba ispisati "Ovojeprimjer".
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_STRINGOVA 10
#define MAX_ZNAKOVA 50
#include <stdio.h>

int main()
{
	char string[MAX_STRINGOVA][MAX_ZNAKOVA];

	for (int i = 0; i < MAX_STRINGOVA; i++) {
		gets_s(string[i]);

		for (int j = 0; j < MAX_ZNAKOVA; j++) {
			if (string[i][j] == ' ') {
				for (int k = j; k < MAX_ZNAKOVA; k++) {
					string[i][k] = string[i][k+1];
					if (string[i][k] == ' ') 
						j--;
				}
			}
		}
	}

	for (int i = 0; i < MAX_STRINGOVA; i++)
		printf("%s\n", string[i]);

	return 0;
}
