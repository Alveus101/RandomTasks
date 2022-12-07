/*
Napiši program koji će uz minimalan utrošak memorije kreirati i popuniti
cjelobrojno polje P sa parnim brojevima u intervalu [2,M]. Polje treba biti
sortirano po uzlaznoj vrijednosti svojih elemenata
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int m = 0;
	int* polje = NULL;

	scanf("%d", &m);

	polje = (int*)malloc(m * sizeof(int));

	for (int i = 0; i < m; i++) {
		if (i > 0) polje[i] = polje[i - 1] + 2;
		else polje[i] = 2;
	}

	for (int i = 0; i < m/2; i++)
		printf("%d\n", *(polje + i));

	return 0;
}
