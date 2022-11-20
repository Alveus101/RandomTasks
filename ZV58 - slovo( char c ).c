/*
Napiši funkciju koja će malo slovo engleske abecede pretvoriti u veliko, a veliko
u malo. Funkcija vraća promijenjeno slovo. Ukoliko nije riječ o znaku engleske
abecede funkcija vraća 0. Prototip funkcije:
char slovo(char c);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char slovo(char c) {

	if (c >= 'A' && c <= 'Z') return (int)c + 32;
	else if (c >= 'a' && c <= 'z') return (int)c - 32;
	else return 0;
}

int main()
{
	char unos;

	printf("Unesi slovo: ");
	scanf("%c", &unos);

	printf("%c", slovo(unos));

	return 0;
}
