/*
Napiši rekurzivnu funkciju koja će ispisati sve brojeve od N do 1. Prototip
funkcije glasi:
int brojevi(int n);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int brojevi(int n) {

	n--;
	printf("%d\n", n);

	if (n > 1) return brojevi(n);
	else return 1;
}

int main() {
	
	int broj;

	scanf("%d", &broj);
	brojevi(broj);

	return 0;
}
