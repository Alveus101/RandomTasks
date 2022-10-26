/*
Napiši program koji će skratiti razlomak a / b. Nakon skraćivanja razlomak je
potrebno ispisati.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int brojnik, nazivnik, a, b, ostatak = 1, noviBrojnik, noviNazivnik;

	scanf("%d / %d", &brojnik, &nazivnik);

	a = brojnik;
	b = nazivnik;

	while (ostatak != 0) {
		ostatak = a % b;
		a = b;
		b = ostatak;
	}

	noviBrojnik = brojnik / a;
	noviNazivnik = nazivnik / a;

	printf("%d / %d", noviBrojnik, noviNazivnik);

	return 0;
}
