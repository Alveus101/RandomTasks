/*
Davor i Ivica su u Dubaiu i gledaju nebodere. Pošto je to novi grad, sve zgrade su posložene vrlo pravilno - 
te su se Davor i Ivica optimalno pozicionirali kako bi mogli igrati jednu interesantnu igru koju im je
predložio Vlado. Naime, stanu se na način da se između njih pravocrtno nalazi N nebodera, a svaki ima
visinu V. Skicirajmo to na ovaj način:

D 1 5 11 7 14 6 6 I

Davor stoji s lijeve strane i ispred njega su redom neboderi visine 1, 5, 11, 7, 14, 6 i 6 katova.
Ivica naprotiv stoji s druge strane, i neboderi iz njegove perspektive su visoki 6, 6, 14, 7, 11, 5, 1.
Vlado, koji se nalazi negdje dalje od njih treba pogoditi koliko nebodera vidi Davor a koliko Ivica.
Višlji neboder će zakloniti one iza sebe, tako da Davor vidi 4 nebodera: one visine 1, 5, 11 i 14.
Ivica vidi samo 2 nebodera - prvi visine 6, i onaj idući viši od 14 katova.

Vrijede ograničenja:
1 <= N <= 100
1 <= V <= 100
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_NEBODERA 100
#include <stdio.h>

int main() {

	int brojNebodera, brojKatova[MAX_NEBODERA], najviseKatova = 0, davorVidi = 0, ivicaVidi = 0;

	scanf("%d", &brojNebodera);

	for (int i = 0; i < brojNebodera; i++) {
		scanf("%d", &brojKatova[i]);
		if (brojKatova[i] > najviseKatova) {
			najviseKatova = brojKatova[i];
		}
	}

	for (int i = 0; i < brojNebodera; i++) {
		if (brojKatova[i] < najviseKatova) {
			davorVidi++;
		}
		else break;
	}

	for (int i = brojNebodera-1; i > 0; i--) {
		if (brojKatova[i] < najviseKatova) {
			ivicaVidi++;
		}
		else break;
	}

	if (davorVidi >= ivicaVidi) printf("Davor %d\nIvica %d", davorVidi, ivicaVidi);
	else printf("Ivica %d\nDavor %d", ivicaVidi, davorVidi);

	return 0;
}
