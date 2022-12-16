/*
Napiši funkciju koja će sve pozitivne elemente nekog realnog polja M kopirati u
drugo realno polje N. U polju N vrijednosti moraju biti sadržane u susjednim
elementima. Funkcija vraća broj kopiranih elemenata. Ukoliko polje N ima
deklarirano manje elemenata nego polje M, funkcija vraća 0. Prototip funkcije
glasi:
int kopiraj(float M[], int m, float N[], int n);
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_M 5
#define MAX_N 5
#include <stdio.h>

int kopiraj(float M[], int m, float N[], int n) {

	int brojKopiranihElemenata = 0, slobodanIndex = 0;

	if (n < m) return 0;

	for (int i = 0; i < n; i++) {
		if (M[i] > 0) {
			N[slobodanIndex] = M[i];
			brojKopiranihElemenata++;
			slobodanIndex++;
		}
	}
	
	printf("Izgled polja N: { ");
	for (int i = 0; i < MAX_N; i++)
		printf("%.2f, ", N[i]);
	printf("}\n");

	return brojKopiranihElemenata;
}

int main() {
	
	float poljeM[MAX_M]{}, poljeN[MAX_N]{};

	for (int i = 0; i < MAX_M; i++) {
		scanf("%f", &poljeM[i]);
	}

	printf("%d", kopiraj(poljeM, MAX_M, poljeN, MAX_N));

	return 0;
}
