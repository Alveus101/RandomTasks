/*
Napisi program koji ce ispisati sve elemente polja n (max. 50 elemenata) koristeci
aritmetiku pokazivaca. Elemente polja je prethodno potrebno ucitati.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 50
#include <stdio.h>

int main() {
	int n[MAX]{};
	int* pn = n;

	for (int i = 0; i < MAX; i++) 
		scanf("%d", &n[i]);

	for (int i = 0; i < MAX; i++) 
		printf("%d\n", *(pn + i));

	return 0;
}
