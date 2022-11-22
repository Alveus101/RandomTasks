/*
Napiši rekurzivnu funkciju koja računa sumu aritmetičkog niza od člana A do
člana B sa razmakom D. Niz mora biti uzlazni (A < B), inače funkcija vraća 0.
Prototip funkcije glasi:
int suma(int a, int b, int d);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zbroj = 0;

int suma(int a, int b, int d) {

	if (zbroj == 0 && a > b) return 0;
	if (a >= b) return zbroj;

	zbroj += a;

	suma(a + d, b, d);
}

int main() {
	
	int a,b,d;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &d);

	printf("%d", suma(a, b, d));

	return 0;
}
