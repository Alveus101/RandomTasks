/*
Napiši funkciju koja ispisuje sve parne brojeve od 2 do N. Prototip funkcije:
void paran(int N);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void paran(int n) {
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0)
			printf("%d\n", i);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	paran(n);

	return 0;
}
