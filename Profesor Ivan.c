/* 
Zadatak:
Gospodin Ivan je profesor dobar. Svakog se jutra ustane rano, pa se uređuje, pere, brije... 
I dok još kuća miriše na jutarnje pranje na pamet mu pada kako da svoje studente zainteresira za programiranje.
On smišlja tako jednu igru koju će na idućem predavanju zaigrati sa svojim studentima preko poruka kroz MS Teams. 
Ivan će zamisliti jednu životinju, a studenti će morati pogoditi što je zamislio. Svaki student koji se želi igrati 
u zajednički kanal tipka naziv životinje. Nije unaprijed poznato koliko studenata će poslati prijedlog, ali igra završava 
nakon što Ivan natipka koju životinju je zamislio. 
Da bi igra bila programerski zanimljiva studenti moraju napraviti C program koji će učitavati listu studentskih 
poruka sve dok Ivan ne natipka koju životinju je zamislio. Program nakon toga ispisuje koliko je studenata pogodilo 
životinju i to u formatu "Broj studenata koji su pogodili zivotinju: X od Y.", gdje je Y ukupni broj studenata koji su igrali. 
Potrebno je ispisati i listu studenata koji su pogodili životinju.

Moguće je da će se desiti da nitko od studenata ništa ne natipka, a u tom slučaju Ivan tipka što je 
zamislio i prekida se izvođenje programa uz poruku "Vise srece drugi put!". Ista poruka se ispisuje i 
u slučaju da nitko nije pogodio životinju koju je profesor zamislio.

Format poruke koja se šalje kroz MS Teams je:
[11:25] Ime Prezime: tekst 

gdje je moguće da se Ime ili Prezime sastoji od više riječi.

Primjer poruke:
[11:25] Prosper Matkovic: ok, a koje gradivo ulazi u iducu pripremu/ labos?

VAŽNO: Preporuka je da se zadatak riješi korištenjem funkcija i polja pokazivača.

TC #1:
[11:25] Bogadi Alen: Kameleon
[11:25] Begovic Amir: Magarac
[11:25] Novak Anel: Tapir
[11:25] Milanja Ante: Jelen
[11:25] Mavracic Antonio: Morski pas
[11:35] Dutkovic Ivan: Vuk
[11:35] Kulic Ivan: Orao
[11:53] Prekratic Ivan: Kameleon
[11:53] Vuletic Jaksa: Krava
[11:53] Bakaric Jan: Kameleon
[11:53] Mladar Jan: Majmun
[12:13] Bakran Josip: Slon
[12:13] Profesor Ivan: Kameleon

Broj studenata koji su pogodili zivotinju: 3 od 12.

Studenti koji su pogodili zivotinju:
Bogadi Alen
Prekratic Ivan
Bakaric Jan

TC #2: 
[14:27] Profesor Ivan: Pas

Vise srece drugi put!

TC #3:
[17:22] Kopjar Mario: Tapir
[17:22] Antonov Mark: Krava
[17:22] Brigljevic Marko: Zmija
[17:24] Osmanovic Marko: Sokol
[17:24] Vukovic Marko: Pingvin
[17:30] Kis Matej: Majmun
[17:30] Aleksic Matija: Zirafa
[17:24] Trzic Mihael: Koza
[17:24] Profesor Ivan: Mrav

Broj studenata koji su pogodili zivotinju: 0 od 8.

Vise srece drugi put!

TC #4:
[12:45] Lovras Lucija: Medvjed
[12:45] Doki Marko: A sto se to igrate?
[12:45] Bashir S B Yousef: Papagaj
[12:45] Maljkovic Mislav: Krava
[12:45] Przic Petar: Pile
[12:45] Jaki Ljutomir: Robot
[12:45] Kolonic Luka: Leptir
[12:46] Profesor Ivan: Papagaj

Broj studenata koji su pogodili zivotinju: 1 od 7.

Studenti koji su pogodili zivotinju:
Bashir S B Yousef
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PORUKA 100
#define MAX_CHAR 100


int odrediPobjednike(char** poruke, char* zivotinja, char** pobjednici) {
	
	int kol = 0, j = 0;
	char *found = NULL, *ime = NULL, *dvotocka = NULL;
	char imestring[50], porukalwr[MAX_PORUKA], zivotinjalwr[50];

	strcpy(imestring, "");

	// Prolaz kroz sve poruke
	for (int i = 0; i < MAX_PORUKA; i++) {
		if (strlen(poruke[i])) {
			
			// Prebacujemo poruku i zivotinju u lowercase da detekcija nije case sensitive
			strcpy(porukalwr, poruke[i]);
			strcpy(zivotinjalwr, strtok(zivotinja, ": "));

			_strlwr(porukalwr);
			_strlwr(zivotinjalwr);

			found = strstr(porukalwr, zivotinjalwr);

			if (found) {
				// Izvlacenje imena studenta iz poruke i pohranjuje ga u pobjednike

				ime = strchr(poruke[i], ' ');
				ime++;

				for (j = 0; j < strlen(ime); j++) {
					if (ime[j] != ':')
						imestring[j] = ime[j];
					else break;
				}
				imestring[j] = '\0';

				strcpy(pobjednici[kol], imestring);

				kol++;
			}
		}
	}

	return kol;
}


int main() {
	int i = 0, broj_pobjednika = 0;
	char input[MAX_CHAR];
	char *zivotinja;

	char** poruke = (char**)malloc(MAX_PORUKA * sizeof(char*));

	for (int i = 0; i < MAX_PORUKA; i++) {
		poruke[i] = (char*)malloc(MAX_CHAR * sizeof(char));
		strcpy(poruke[i], "");
	}

	char** pobjednici = (char**)malloc(MAX_PORUKA * sizeof(char*));

	for (int i = 0; i < MAX_PORUKA; i++) {
		pobjednici[i] = (char*)malloc(MAX_CHAR * sizeof(char));
		strcpy(pobjednici[i], "");
	}

	while (1) {
		scanf("%100[^\n]%*c", input);

		if (strstr(input, "Profesor Ivan") != NULL) {
			
			zivotinja = strstr(input, ": ");
			break;
		}
		else {
			strcpy(poruke[i], input);
			i++;
		}
	}

	broj_pobjednika = odrediPobjednike(poruke, zivotinja, pobjednici);
	
	if( i > 0 ) printf("Broj studenata koji su pogodili zivotinju: %d od %d.\n\n", broj_pobjednika, i);
	if (broj_pobjednika > 0) {
		printf("Studenti koji su pogodili zivotinju:\n");

		for (int j = 0; j < broj_pobjednika; j++) {
			printf("%s\n", pobjednici[j]);
		}
	}
	else printf("Vise srece drugi put!");

	return 0;
}
