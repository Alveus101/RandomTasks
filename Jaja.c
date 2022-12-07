/*
Europska unija propisuje da sva jaja moraju imati promjer između Xmm i Ymm ( X i Y se ucitavaju i 0<x,y<65 ).
Vi, kao OPG koji ima kokice i proizvodi jaja, morate ispoštovati zadane krieterije.

Za ulazni niz jaja, potrebno je izdvojiti ona koja prolaze navedene kriterije, te na kraju ispisati koja jaja
zadovoljavaju kriterije.

Izdvajanje jaja je potrebno obaviti u funkciji, a rezultate nije dozvoljeno ispisivati u istoj funkciji.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 50
#include <stdio.h>

int provjeri_jaje(int index, int promjerJajeta, int x, int y);

int main() {

	int x = 0, y = 0, brojJaja = 0, jaja[MAX], dobraJaja[MAX]{}, counter = 0;

	while (brojJaja == 0) {
		scanf("%d", &x);
		scanf("%d", &y);
		scanf("%d", &brojJaja);

		if (x < 1 || y < 1 || x > 65 || y > 65) {
			printf("Neispravan unos!");
			brojJaja = 0;
			continue;
		}
	}
	
	for (int i = 0; i < brojJaja; i++) {
		scanf("%d", &jaja[i]);
		dobraJaja[i] = provjeri_jaje(i, jaja[i], x, y);
		if (dobraJaja[i] > 0) counter++;
	}

	printf("Uvjete zadovoljava %d jaja: ", counter);

	for (int i = 0; i < brojJaja; i++) {
		if( dobraJaja[i] > 0 )
			printf("%d ", jaja[dobraJaja[i]]);
	}

	return 0; 
}

int provjeri_jaje(int index, int promjerJajeta, int x, int y) {

	int gornjaGranica = 0, donjaGranica = 0;

	if (x > y) gornjaGranica = x, donjaGranica = y;
	else gornjaGranica = y, donjaGranica = x;
	
	if (promjerJajeta >= donjaGranica && promjerJajeta <= gornjaGranica)
		return index;

	return -1;
}
