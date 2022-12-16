/*
Napiši program koji će učitati prirodan broj N. Program treba generirati isto
toliko slučajnih brojeva u intervalu [0,99], te ih ispisati od najmanjeg prema
najvećem.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_BROJEVA 100
#define INTERVAL 99
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n, brojevi[MAX_BROJEVA], temp = 0;

	scanf("%d", &n);
	if (n >= MAX_BROJEVA) return printf("Prevelik broj! Uneseno je: %d, a MAX_BROJEVA iznosi: %d", n, MAX_BROJEVA);

	srand(time(NULL));

	for (int i = 0; i < n; i++)
		brojevi[i] = rand()%INTERVAL;

	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (brojevi[j] > brojevi[j + 1]) {
				temp = brojevi[j];
				brojevi[j] = brojevi[j + 1];
				brojevi[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", brojevi[i]);
	}

	return 0;
}
