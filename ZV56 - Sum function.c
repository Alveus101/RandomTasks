/*
Napiši funkciju koja vraća sumu 2 realna broja. Prototip funkcije:
float suma(float a, float b);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float suma(float a, float b) {
	return a + b;
}	

int main()
{
	float a, b;
	scanf("%f", &a);
	scanf("%f", &b);

	printf( "%.2f", suma(a, b) );

	return 0;
}
