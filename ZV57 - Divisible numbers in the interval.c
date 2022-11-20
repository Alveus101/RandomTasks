/*
Napiši funkciju koja će za zadani interval brojeva vratiti koliko ih je djeljivo sa N.
int djeljivo(int a, int b, int n);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int djeljivo(int a, int b, int n) {
	int counter = 0;

	for (int i = a; i <= b; i++) {
		if (i % n == 0)
			counter++;
	}

	return counter;
}

int main()
{
	int a, b, n;

	printf("Unesi najmanji moguci broj intervala: ");
	scanf("%d", &a);
	printf("Unesi najveci moguci broj intervala: ");
	scanf("%d", &b);
	printf("Unesi djeljitelj N: ");
	scanf("%d", &n);

	printf("U intervalu [%d,%d] sa brojem %d djeljivo je ukupno %d brojeva.", a,b,n,djeljivo(a,b,n));

	return 0;
}
