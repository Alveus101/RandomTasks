/*
Napiši funkciju koja vraća faktorijel određenog broja. Prototip funkcije:
double faktorijel(int n);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double faktorijel(int n){

	int umnozak = 1;
	for (int i = 1; i <= n; i++)
		umnozak *= i;

	return umnozak;

}

int main()
{
	int n;
	printf("Unesi broj: ");
	scanf("%d", &n);

	printf("%d! = %.1lf", n, faktorijel(n));

	return 0;
}
