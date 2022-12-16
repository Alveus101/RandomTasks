/*
Vaš je zadatak isprogramirati jednostavniju verziju igrice:

Polje za igru može biti veliko NxN, ali maksimalno 10x10 i minimalno 3x3 - u slučaju unosa neispravne dimenzije polja ispisuje se poruka "Nedozvoljena dimenzija polja!"
Za pobjedu je potrebno okomito spojiti N znakova (dijagonalno i vodoravno spojeni znakovi ne donose pobjedu!) 

Napomene vezane uz unos (pogledati test case):
- Na početku igre traži se informacija o tome: koliko je veliko polje, koliko znakova treba spojiti za pobjedu i tko će igrati prvi
- Igrači naizmjence unose pozicije za igru
- Svaki igrač unosi poziciju u formatu: redak stupac

Napomene vezane uz ispis (pogledati test case):
- Prazno polje sadrži znak '-'
- Za razmak između znakova prilikom ispisa polja koristiti specifikator %2c
- Potrebno je ispisati stanje polja: jednom na početku igre (prazno polje) i nakon svakog kruga igre
Nakon ispisa svakog stanja polja ispisuje se jedan prazan red '\n'

Napomena: za realizaciju 2D polja za igru OBAVEZNO koristiti 2D polje! Ukoliko se polje za igru ne realizira kao dvodimenzionalno polje - priprema se neće priznati.

Na početku igre traži se informacija o tome: koliko je veliko polje (3x3), koliko znakova treba spojiti za pobjedu (3) i tko će igrati prvi (X).
Igrači naizmjence unose pozicije za igru. Svaki igrač unosi poziciju u formatu: redak stupac.
Na početku igre polje je prazno. Ispisuje se stanje polja.
Zatim igrači unose svoje pozicije: prvi unosi X igrač (1 1), a zatim O (1 2). Nema pobjednika. Ispisuje se stanje polja nakon unosa.
Igrači ponovo unose svoje pozicije: prvi unosi X igrač, a zatim O. Nema pobjednika. Ispisuje se stanje polja nakon unosa.
Igrači ponovo unose svoje pozicije: prvi unosi X igrač, a zatim O. Pobjednik je igrač X jer je prvi spojio svoja 3 znaka. Ispisuje se stanje polja nakon unosa. 

Test caseovi su dolje.
*/

#define _CRT_SECURE_NO_WARNINGS

#define MAX_POLJE 10
#define MIN_POLJE 3

#define TRUE 1
#define FALSE 0

#include <stdio.h>

int main() {

	int visinaPolja, sirinaPolja, kolikoZnakova, krajIgre = FALSE, redak, stupac, counter = 0, nepravilanUnos = TRUE;
	char polje[MAX_POLJE][MAX_POLJE], tkoIgraSljedeci, pobjednik = '?';

	while (nepravilanUnos == TRUE) {
		scanf("%dx%d", &visinaPolja, &sirinaPolja);
		
		if (visinaPolja >= MIN_POLJE && visinaPolja <= MAX_POLJE && sirinaPolja >= MIN_POLJE && sirinaPolja <= MAX_POLJE)
			nepravilanUnos = FALSE;
		else printf("Nedozvoljena dimenzija polja!\n");
	}
		
	scanf("%d", &kolikoZnakova);
	scanf(" %c", &tkoIgraSljedeci);

	for (int i = 0; i < visinaPolja; i++) {
		for (int j = 0; j < sirinaPolja; j++) {
			polje[i][j] = '-';
		}
	}

	while (!krajIgre) {

		for (int i = 0; i < visinaPolja; i++) {
			for (int j = 0; j < sirinaPolja; j++) {
				printf("%2c", polje[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		if (pobjednik != '?') {
			printf("Pobjednik je igrac %c!", pobjednik);
			break;
		}
		
		for (int k = 0; k < 2; k++) {
			scanf("%d", &redak);
			scanf("%d", &stupac);

			polje[redak - 1][stupac - 1] = tkoIgraSljedeci;

			for (int i = 0; i < sirinaPolja; i++) {
				for (int j = 0; j < visinaPolja; j++) {
					if (polje[j][i] == tkoIgraSljedeci)
						counter++;
				}
				if (counter == kolikoZnakova) {
					if( pobjednik == '?' ) pobjednik = tkoIgraSljedeci;
					break;
				}
				counter = 0;
			}

			if (tkoIgraSljedeci == 'X') tkoIgraSljedeci = 'O';
			else if (tkoIgraSljedeci == 'O') tkoIgraSljedeci = 'X';
		}
	}

	return 0;
}

/*
Test Case #1

Input:
3x3
3
X
1 1
1 2
3 1
2 2
2 1
3 2

Output:
 - - -
 - - -
 - - -

 X O -
 - - -
 - - -

 X O -
 - O -
 X - -

 X O -
 X O -
 X O -

Pobjednik je igrac X!

Test Case #2

Input:
3x5
3
O
2 3
1 5
1 3
2 5
1 1
3 5

Output:
 - - - - -
 - - - - -
 - - - - -

 - - - - X
 - - O - -
 - - - - -

 - - O - X
 - - O - X
 - - - - -

 O - O - X
 - - O - X
 - - - - X

Pobjednik je igrac X!

Test case #3

Input:
10x9
4
X
2 3
3 3
2 4
4 3
2 5
5 3
2 6
6 3

Output:
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -

 - - - - - - - - -
 - - X - - - - - -
 - - O - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -

 - - - - - - - - -
 - - X X - - - - -
 - - O - - - - - -
 - - O - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -

 - - - - - - - - -
 - - X X X - - - -
 - - O - - - - - -
 - - O - - - - - -
 - - O - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -

 - - - - - - - - -
 - - X X X X - - -
 - - O - - - - - -
 - - O - - - - - -
 - - O - - - - - -
 - - O - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -

Pobjednik je igrac O!

Test Case #4

Input:
10x9
1
O
1 1
1 2

Output:
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -

 O X - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -
 - - - - - - - - -

Pobjednik je igrac O!

Test Case #5

Input:
1x3
1x1
11x10
100x100
2x2
3x1
0x0
3x5
3
O
2 3
1 5
1 3
2 5
1 1
3 5

Output:
Nedozvoljena dimenzija polja!
Nedozvoljena dimenzija polja!
Nedozvoljena dimenzija polja!
Nedozvoljena dimenzija polja!
Nedozvoljena dimenzija polja!
Nedozvoljena dimenzija polja!
Nedozvoljena dimenzija polja!
 - - - - -
 - - - - -
 - - - - -

 - - - - X
 - - O - -
 - - - - -

 - - O - X
 - - O - X
 - - - - -

 O - O - X
 - - O - X
 - - - - X

Pobjednik je igrac X!
*/
