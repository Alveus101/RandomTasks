/*
Napiši program koji će provjeriti da li je učitani broj prost broj.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int broj;

	scanf("%d", &broj);

	for (int i = 2; i < broj; i++) {
		if (broj % i == 0) {
			printf("Broj nije prost!");
			return 0;
		}
		else {
			printf("Broj je prost!");
			return 0;
		}
	}

	return 0;
}
