// Mala Anica nikako ne moze nauciti tablicu mnozenja, te je odlucila zamoliti svoje prijatelje s TVZ - a(Vas) koji 
// uce programirati u C - u da joj napisu program koji �e joj za odredjeni broj K ispisati rezultate mnozenja svih 
// parnih brojeva od 1 do N sa zadanim brojem.Anica je nacula od svojih prijatelja iz skole da ce ju uciteljica pitati 
// tablicu mnozenja tako da zadani broj pomnozi samo s parnim brojevima i izrecitira rezultate na nacin da prvih X 
// i posljednjih Y brojeva kaze normalnim redoslijedom, a one u sredini obrnutim redoslijedom.
//
// Potrebno je ucitati brojeve N, K, X i Y, te ispisati rezultate u trazenom formatu.
//
// X + Y ce biti manji od N / 2, tj., vrijedi X + Y < N / 2.

#define _CRT_SECURE_NO_WARNINGS
#define MAX_REZULTATA 100
#include <stdio.h>

int main() {
	int k, n, x, y, i, brojRezultata = 0, rezultati[MAX_REZULTATA]{};

	printf("N -> ");
	scanf("%d", &n);
	
	printf("K -> ");
	scanf("%d", &k);

	printf("X -> ");
	scanf("%d", &x);
	
	printf("Y -> ");
	scanf("%d", &y);

	if (x + y >= n / 2) {
		printf("X + Y moraju biti manji od N / 2, a kod tebe je x:%d + y:%d = %d", x, y, x + y);
		return 0;
	}

	for (i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < MAX_REZULTATA; j++) {
				if (rezultati[j] == 0) {
					rezultati[j] = i * k;
					brojRezultata++;
					break;
				}
			}
		}
	}

	for (i = 0; i < x; i++) {
		printf("X %d\n", rezultati[i]);
	}

	for( i = brojRezultata - y; i > x; i--){
		printf("%d\n", rezultati[i-1]);
	}

	for (i = brojRezultata - y; i < brojRezultata; i++) {
		printf("Y %d\n", rezultati[i]);
	}

	return 0;
}
