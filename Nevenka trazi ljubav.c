/*
Zadatak: 

Nevenka Bekavac (40) iz Splita već nekoliko godina zaredom prijavljuje se u emisiju „Ljubav je na selu“ kako bi pronašla ljubav svog života. Međutim, do sada ju još uvijek nije pronašla. Ona zna što želi i kako bi trebao izgledati savršeni odabranik njenog srca, ali takav se još nije pojavio ni u emisiji ni u njenom životu. Kako bi joj pomogli, voditeljica showa Marijana Batinić i posrednik za ljubav Gangster pomažu Nevenki da pronađe svog princa na bijelom konju te joj šalju SMS poruke (jer Nevenka ne koristi podatkovne usluge svog mobilnog operatera) u kojima se nalaze informacije o potencijalnim ženicima. Od dobivenog skupa SMS poruka Nevenka se svaki put mora odlučiti za kandidate za spoj i njihova imena i prezimena poslati porukom nazad Marijani i Gangsteru.

Od svih kandidata Nevenka će se pristati naći s onim koji posjeduje neku od sljedećih karakteristika:

Mlađi je od nje ili maksimalno 5 godina stariji
Crn
Visok
Bogat
U svaku SMS poruku stane maksimalno 160 znakova, te su poruke često jako sažete, a u njima se može nalaziti opis i više kandidata. Ime i prezime kandidata uvijek se nalazi napisano na početku svake SMS poruke. Ukoliko u jednoj poruci ima više kandidata isti su odvojeni znakom '#'. Nevenka nikada ne zna koliko će dobiti SMS poruka (svaka SMS poruka prima se kao zasebni string). Prije nego dobije SMS-ove s potencijalnim ženicima, Nevenka dobiva kontrolni SMS (također string!) u kojem piše broj poruka koje će dobiti.

Napišite funkciju prototipa char *trazi(char *sms) koja će na temelju primljenih SMS poruka pronaći kandidate koji se sviđaju Nevenki te umjesto nje složiti SMS poruku (funkcija kreira znakovni niz s imenima i prezimenima kandidata iz SMS poruke) koja se šalje Marijani i Gangsteru.
Napomena: za pojašnjenje pogledati video na adresi https://web.facebook.com/LjubavJeNaSelu/videos/1271507289560096/ i test primjere.

Nevenka je u ovom primjeru dobila dvije SMS poruke i kako oba kandidata zadovoljavaju njene kriterije u povratnoj SMS poruci šalje imena i prezimena oba kandidata.
Zigo je mlađi i crn, a Matija je bogat.

TC #1
2
Goran Zigo (38). Lucani. Uzgaja ovce i vino. Zivi s majkom, ocem i bratom. Crn.
Matija Prebic (40). Bogat.

Goran Zigo
Matija Prebic

TC #2
3
Stanko Rajcic (52). Nevest. Voli pjevati ojkalicu. Bio u braku. Ne želi vegetarijanku.
Alojz Kanceljak (31). Glogovac. Njegova obitelj prodaje mlijeko jednoj poznatoj maloj mljekari. Clan je DVD-a i igra nogomet. Sportas.
Drazen Bozic (41). Grude. Crn i visok. Strojarski tehnicar. Zivi s majkom. Uzgaja duhan, smilje i lozu. Navijac Hajduka.

Alojz Kanceljak
Drazen Bozic

TC #3
3
Ranko Pavlovic Rumeni (39). Kokinci. Bavi se uzgojem svinja te radi i kao licilac. Dvoje djece. Na youtube kanalu postavlja skeceve.
Danko Bezmalinovic (57). Brac. Zidar.#Josip Juric (25). Sportas. Vinar. Zivi sa sestrom.#Ivica Stapic (52). Habjanovci. Autoelektricar.
Stipe Filipovic (40). Aleksinci. Ima brk. Uzgaja ovce. Ne podnosi nepravdu i laz.

Ranko Pavlovic Rumeni
Josip Juric
Stipe Filipovic
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 10
#define MAX_ZNAKOVA 160

char* trazi(char* sms) {
	char karakteristike[3][10] = {
		"Crn",
		"Visok",
		"Bogat"
	};
	char rezultat[100], dobstr[100], kandidati[10][MAX_ZNAKOVA];
	char* found = NULL, *multiple = NULL;
	int godine = 0, k = 0;

	strcpy(rezultat, "");
	strcpy(dobstr, "");

	// Dijeljenje SMS-a na kandidate

	multiple = strtok(sms, "#");
	
	if (multiple != NULL) {
		while (multiple != NULL) {
			strcpy(kandidati[k], multiple);
			multiple = strtok(NULL, "#");
			k++;
		}
	}
	else {
		k = 1;
		strcpy(kandidati[0], sms);
	}

	for (int j = 0; j < k; j++) {
		found = strstr(kandidati[j], "(");

		strncpy(dobstr, ++found, 2);
		if (strlen(dobstr) > 1) dobstr[2] = '\0';
		
		godine = atoi(dobstr);

		found = NULL;

		if (godine <= 45) {
			strcat(rezultat, strtok(kandidati[j], "("));
		}
		else for (int i = 0; i < 3; i++) {
			found = strstr(kandidati[j], karakteristike[i]);
			if (found != NULL) {
				strcat(rezultat, strtok(kandidati[j], "("));
				break;
			}
		}
	}

	if( strlen(rezultat) > 5 ) printf("%s\n", rezultat);

	return rezultat;
}

int main() {

	char kol_poruka_str, kandidati[100];
	int kol_poruka = 0, count = 0;
	char poruke[MAX][MAX_ZNAKOVA];

	scanf("%c\n", &kol_poruka_str);

	kol_poruka = (int)kol_poruka_str - '0';

	while (count != kol_poruka) {
		scanf("%160[^\n]%*c", poruke[count]);
		count++;
	}

	for (int i = 0; i < count; i++) {
		trazi(poruke[i]);
	}

	return 0;
}
