/*
Ana ima niz kriterija prema kojima bira svog idealnog partnera. Vi ste tu da joj pomognete da si lakše i brže izabere svog idealnog partnera. 

Na početku je potrebno učitati Anine kriterije za izbor:
interval za visinu u centimetrima - dva cijela broja u intervalu (50, 250], te razlika većeg i manjeg ne smije biti veća od 35
interval za težinu u kilogramima - dva cijela broja u intervalu  [50, 100], te razlika većeg i manjeg mora biti veća od 5
interval za broj godina .- dva cijela broja u intervalu (15, 100), te razlika većeg i manjeg mora biti točno 5
Za svaki interval koji se učitava potrebno je tražiti ponovni unos oba cijela broja iz intervala ukoliko gornja pravila nisu zadovoljena.

Nakon toga potrebno je učitati cijeli broj N u intervalu (3, 20]. Također tražiti ponovni unos ako broj nije u intervalu.

Zatim učitati N podataka o potencijalnim partnerima: visinu, tezinu i broj godina.

Na kraju programa ispisati koliko partnera odgovara Aninim zahtjevima. Partner odgovara zahtjevima ako zadovoljava sva 3 uvjeta.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_PARTNERA 20
#include <stdio.h>

int main() {
	int step = 0, counter = 0, minVisina, maxVisina, minTezina, maxTezina, minGodine, maxGodine, brojPartnera, partnerInfo[MAX_PARTNERA][3];
	
	while (step != 4) {
		if (step == 0) {
			scanf("%d", &minVisina);
			scanf("%d", &maxVisina);

			if ((minVisina > 50 && maxVisina <= 250) && maxVisina - minVisina <= 35) {
				step++; 
				continue;
			}
			else printf("Nepravilni unos visine!\n");
		}
		else if (step == 1) {
			scanf("%d", &minTezina);
			scanf("%d", &maxTezina);

			if (minTezina >= 50 && maxTezina <= 100 && maxTezina - minTezina > 5) {
				step++; 
				continue;
			}
			else printf("Nepravilni unos tezine!\n");
		}
		else if (step == 2) {
			scanf("%d", &minGodine);
			scanf("%d", &maxGodine);

			if (minGodine > 15 && maxGodine < 100 && maxGodine - minGodine == 5) {
				step++; 
				continue;
			}
			else printf("Nepravilni unos godina!\n");
		}
		else if (step == 3) {
			scanf("%d", &brojPartnera);

			if (brojPartnera > 3 && brojPartnera <= MAX_PARTNERA) {
				step++; 
				continue;
			}
			else printf("Nepravilni unos broja partnera!\n");
		}
	}

	for (int i = 0; i < brojPartnera; i++) {
		scanf("%d", &partnerInfo[i][0]);
		scanf("%d", &partnerInfo[i][1]);
		scanf("%d", &partnerInfo[i][2]);
	}

	for (int i = 0; i < brojPartnera; i++) {
		if (partnerInfo[i][0] >= minVisina && partnerInfo[i][0] <= maxVisina) {
			if (partnerInfo[i][1] >= minTezina && partnerInfo[i][1] <= maxTezina) {
				if (partnerInfo[i][2] >= minGodine && partnerInfo[i][2] <= maxGodine) {
					counter++;
				}
			}
		}
	}

	if (counter == 1 || counter > 4) printf("Prolazi kriterije: %d osoba.", counter);
	else printf("Prolazi kriterije: %d osobe.", counter);

	return 0;
}
