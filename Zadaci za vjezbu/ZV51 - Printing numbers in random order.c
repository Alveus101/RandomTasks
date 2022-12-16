/*
Napiši program koji će slučajnim redoslijedom ispisati sve brojeve od 1 do N.
Niti jedan broj u zadanom intervalu [1,N] ne smije biti ispisan dva ili više puta.
*/

#define _CRT_SECURE_NO_WARNINGS
#define INTERVAL 99
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n, random, brojevi[INTERVAL]{}, redoslijed[INTERVAL]{};

	scanf("%d", &n);
	if (n >= INTERVAL) return printf("Prevelik broj! Uneseno je: %d, a INTERVAL iznosi: %d", n, INTERVAL);

	srand(time(NULL));
	

	for (int i = 1; i <= n; i++) {
		brojevi[i] = i;

		random = (rand() % n)+1;
		for (int j = 0; j <= n; j++) {
			if (redoslijed[j] == random) {
				random = (rand() % n) + 1;
				j = 0;
			}
		}
		redoslijed[i] = random;
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", brojevi[redoslijed[i]]);
	}

	return 0;
}
