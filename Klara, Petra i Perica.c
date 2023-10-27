/*
Zadatak: 

Srednjoškolke Klara i Petra vole se dopisivati preko maaaaaliiih papirića za vrijeme nastave, jer su mobiteli zabranjeni. 
Međutim, kako ne sjede zajedno u klupi jer Klara sjedi u drugom redu do prozora, a Petra u četvrtom redu do zida osmislile 
su posebnu tajnu abecedu za dopisivanje putem papirića. Kada napišu poruku uvijek ju šalju preko nekoliko ljudi u razredu, 
pa tako i preko Perice.

Pericu jako zanima oko čega se Petra i Klara dopisuju te je na temelju par poruka uspio dešifrirati tajnu abecedu, ali bi 
volio da mu vi pomognete napisati program koji će brzinski prevesti poruku kad mu dospije u ruke kako Klara i Petra ne bi 
skužile da ju Perica čita.

Perica je primijetio da:

Jedna poruka se uvijek sastoji od 10 brojeva
Svaki broj u poruci je zapravo slovo engleske abecede: 1 je A, 2 je B… Z je 26
Ukoliko je 10. broj 0, onda to zapravo znači da na kraju poruke piše „KRAJ PORUKE!
Ukoliko na kraju poruke ne piše broj 0 onda znači da slijedi papirić s ostatkom teksta koji je vezan uz prethodnu poruku
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_PORUKA 10

#include <stdio.h>

int main() {
	
	int poruka[MAX_PORUKA];

	for (int i = 0; i < MAX_PORUKA; i++) {
		scanf("%d", &poruka[i]);
	}

	for (int i = 0; i < MAX_PORUKA; i++) {
		
		if( poruka[i] > 0 ) printf("%c", (poruka[i]+64));
		
		if (i < 9) printf(" ");

		if (i == 9 && poruka[9] == 0) {
			printf("\nKRAJ PORUKE!");
		}
	}

	return 0;
}

