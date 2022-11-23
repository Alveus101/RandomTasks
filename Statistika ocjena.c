/*
Napišite C program koji grafički prikazuje statistiku ocjena na nekom kolegiju.
Od korisnika se traži unos broja studenata ( između 2 i 50 ) sve dok se ne unese broj iz intervala.
Nakon toga se u polje unose ocjene ( od 1 do 5 ) za svakog studenta. 
Ukoliko se unese ocjena izvan intervala, potrebno je ponoviti unos.

Potrebno je kreirati i ispisati matricu koja će prikazivati statistiku na način da se u svakom stupcu
gledano odozda prema gore nalazi znakova "*" koliko je bilo odgovarajućih ocjena.
Ostala mjesta u matrici ( od visine koja je jednaka broju studenata ) sadržavaju točke ".".

Primjer:
Za ocjene 2 2 3 3 5 3 1 matrica izgleda ovako:

. . . . .
. . . . .
. . . . .
. . . . .
. . * . .
. * * . .
* * * . *

*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 50
#include <stdio.h>

int main() {
	
	int brojStudenata = 0, counter = 0, unos, ocjene[5]{};
	char matrica[MAX][5];

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < 5; j++) {
			matrica[i][j] = '.';
		}
	}

	while (brojStudenata < 2 || brojStudenata > 50) {
		scanf("%d", &brojStudenata);
	}

	while (counter != brojStudenata) {
		scanf("%d", &unos);

		if (unos >= 1 && unos <= 5) {
			ocjene[unos - 1]++;
			counter++;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < ocjene[i]; j++)
			matrica[brojStudenata-1-j][i] = '*';
	}

	for (int i = 0; i < brojStudenata; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%c", matrica[i][j]);
		}
		printf("\n");
	}

	return 0;
}
