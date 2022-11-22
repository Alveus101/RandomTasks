/*
Napiši funkciju koja će za jedno cjelobrojno 1D polje sa poznatim brojem
elemenata vratiti broj elemenata u kojima se nalaze parni brojevi. Prototip
funkcije:
int paran(int polje[], int br_elem);
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 5
#include <stdio.h>

int paran(int polje[], int br_elem) {

	int kolicinaParnih = 0;

	for (int i = 0; i < br_elem; i++) {
		if (polje[i] % 2 == 0)
			kolicinaParnih++;
	}

	return kolicinaParnih;

}

int main() {
	
	int niz[MAX];

	for (int i = 0; i < MAX; i++) {
		scanf("%d", &niz[i]);
	}

	printf("Pronadjen je sljedeci broj parnih brojeva: %d", paran(niz, MAX));

	return 0;
}
