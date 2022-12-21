/*
Tajne poruke 2 - Romeo i Julija šalju jedno drugom SMS poruke, ali tako da ih nitko drugi osim njih ne može razumjeti.
Tajna je u tajnom ključu - nizu znakova kojim se zamjenjuju mala slova engl. abecede na način da svako slovo ima odgovarajući znak u ključu, 
na primjer slovu 'a' pripada 1. znak, slovu 'z' 26, znak. Osim niza znakova, Romeo i Julija su dogovorili još i slijedeće: znamenke (brojevi od 0 do 9) 
u porukama suti isti brojevi, a umjesto znaka za razmak u tajnoj poruci će ga zamijeniti okomita crta T. Dakle, zadan je ključ u obliku stringa i Vi 
njega trebate učitati.Nakon toga slijedi tajna poruka koju Romeo upućuje Juliji. Ali - eto nevolje - Julija ne umije prevesti tajnu poruku - izgubila je 
"ključ". Pomozite Juliji da Romeovu poruku "prevede" i sazna što je to njoj njen dragi Romeo napisao.Julija ima program za prevođenje otvorene poruke u 
tajnu i sročila je odgovor na Romeovu poruku ali - opet nevolje - Romeo je lijen prevadati poruku od Julije. Pomozite i Romeu da razazna što je njegova 
draga Julija njemu poručila. Poruke Romeo i Julija šalju naizmjence i njih može biti više - kraj je kada jedno od njih bilo gdje u poruci napiše riječi 
"idem" i "spat".

Ukratko, napišite program u C u kojem prvo učitate ključ - niz od 26 znakova pomoću kojega ćete tajne znakovne poruke pretvarati u otvorene poruke.
Nakon toga učitate tajnu poruku - naizmjence od Romea I Julije. Poruke su kratke s manje od 80 znakova. U posebnu funkciju prevedite tajnu poruku u 
otvorenu pomoću ključa, uzevši u obzir dodatni dogovor o znamenkama i razmaku.
U glavnoj funkciji ispišite otvorenu poruku.
Postupak ponavljate sve dok bilo gdje u poruci ne dobijete riječi "idem" i "spat". Na kraju ispišite koliko je bilo poruka.

Test caseovi su dolje.
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_ZNAKOVA 80
#define MAX_KLJUC 26
#include <stdio.h>
#include <string.h>

void dekodirajPoruku(char* kljuc, char* poruka, char* pdekodiranaPoruka) {
	for (int i = 0; i < strlen(poruka); i++) {
		for (int j = 0; j < MAX_KLJUC; j++) {
			if (poruka[i] == kljuc[j]) pdekodiranaPoruka[i] = (char)j+97;
			else if (poruka[i] == '|') pdekodiranaPoruka[i] = ' ';
			else if (poruka[i] >= '0' && poruka[i] <= '9') pdekodiranaPoruka[i] = poruka[i];
		}
	}
	pdekodiranaPoruka[strlen(poruka)] = '\0';
}

int main() {
	char kljuc[MAX_KLJUC+1], poruka[MAX_ZNAKOVA], dekodiranaPoruka[MAX_ZNAKOVA];
	char* pdekodiranaPoruka = dekodiranaPoruka;
	int brojPoruka = 0;

	scanf("%[^\n]s", kljuc);
	
	while (1) {
		scanf("\n%[^\n]s", poruka);

		dekodirajPoruku(kljuc, poruka, pdekodiranaPoruka);

		printf("%s\n", dekodiranaPoruka);

		brojPoruka++;

		if (strstr(pdekodiranaPoruka, "idem") != NULL || strstr(pdekodiranaPoruka, "spat") != NULL) {
			break;
		}
	}

	printf("Broj poruka: %d", brojPoruka);

	return 0;
}
/*
Test case #1

Prvo je izlazna poruka "Ucitaj kljuc". Nakon toga slijede pozivi Romeu i Juliji za unos 
tajne poruke i ispis otvorene poruke. Ako poruka bilo gdje sadrži riječi "idem" i "spat" - 
prekida se daljnje učitavanje poruka i ispisuje broj unesenih poruka.

Ulaz:
*-_=]$%,:[#>({)@/'&;?}+¸<!
=)=[:|}]_]'*&|?|9
{]|()%?|-)>:|(]|%>*}*
){=*|:=](|[*|&@*;

Izlaz:
dodji veceras u 9
ne mogu boli me glava
onda idem ja spat
Broj poruka: 3


Test case #2
Ulaz:
*-_=]$%,:[#>({)@/'&;?}+¸<!
=)=[:|){=*|&?;'*|?|:&;)|}':[](]
{]|()%?|?|9|}]_|?|11|*|&*=*|:=](|[*|&@*;

Izlaz:
dodji onda sutra u isto vrijeme
ne mogu u 9 vec u 11 a sada idem ja spat
Broj poruka: 2


Test case #3
Ulaz:
*-_=]$%,;[#>(})@/'&:?{+.<!
%=[]|&;|=)&*=|=)%){)';>;|&()|?|11|*|:]-]|}](*|2|&*:*
-;>*|&*(|(*>)|?|&,)@;}%|@*|}*|$';!?'?|;|]:)|!*#*&};>*
=)-')|)}=*|[*|;=](|&*=*|&@*:

Izlaz:
gdje si dosad dogovorili smo se u 11 a tebe nema 2 sata
bila sam malo u shoping pa na frizuru i eto zakasnila
dobro onda ja idem sada spat
Broj poruka: 3
*/
