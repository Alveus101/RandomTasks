/*
Napiši program koji će provjeriti da li je učitani broj prost broj.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int broj, found = 0;

	scanf("%d", &broj);

	for (int i = 2; i < broj; i++) {
		if (broj % i == 0) {
			found = 1;
		}
		else {
			continue;
		}
	}

	if (found == 1)
		printf("Broj nije prost!");
	else
		printf("Broj je prost!");

	return 0;
}
