/*
Odlazite na city-break u grad Nully, u Francuskoj, i s obzirom da želite obići sve znamenitosti u jednom danu, imate vrlo ograničen prostor u ruksaku.
Samim time, morate se odlučiti što želite ponijeti sa sobom. Stvarima koje želite ponijeti ste izmjerili težinu, i ocijenili koliko vam vrijede.
Primjerice,
- krema za sunčanje je teška 1kg, ali vrijedi 50 jedinica
- štit od Captain America je težak 4kg (plastični) a vrijedi vam 75 jedinica
- sendvič od buđole je težak 2kg, i vrijedi 60 jedinica
- luft madrac je težak 1kg, ali vrijedi 10 jedinica

Pošto možete ponijeti samo 5kg, najoptimalnije je izabrati kremu za sunčanje i štit Captain America koji vrijede zajedno 125 jedinica. 
Druga opcija je da ponesete kremu, sendvič i luftić, i to vrijedi 120 jedinica. 
Što je zaključak? Nećete izgoriti i lijepo ćete izgledati na slikama sa štitom, ali ćete biti gladni.

S ulaza je potrebno učitati dva broja K i N. K označava koliko možete kilograma ponijeti u ruksaku, a N označava broj dostupnih stvari od kojih morate izabrati
Nakon toga slijedi N redaka, a u svakom retku se nalazi broj T i V, gdje je T težina pojedine stvari a V je njena vrijednost.
Na kraju je potrebno ispisati jedan broj: koja je najveća vrijednost koju je moguće ponijeti.

Vrijedi: 1 <= K <= 1000, 1 <= N <= 1000, 0 <= T <= 1000, 0 <= V <= 1000.


TEST CASE #1
Primjer iz teksta - mozemo ponijeti 5kg, imamo 4 stvari na izbor. Najbolje rjesenje se postize sa 125 jedinica vrijednosti.

Ulaz:
5 4
1 50
4 75
2 60
1 10

Izlaz:
125


TEST CASE #2
Stane samo jedna stvar

Ulaz:
5 5
3 20
4 30
5 40
3 50
4 10

Izlaz:
50
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h>

int main() {
	
	int k, n, t, v, data[MAX][2], temp[2], sumaV = 0, sumaK = 0;

	scanf("%d", &k);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		scanf("%d", &v);

		data[i][0] = t;
		data[i][1] = v;
	}

	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (data[j][1] < data[j + 1][1]) {

				temp[0] = data[j][0];
				data[j][0] = data[j + 1][0];
				data[j + 1][0] = temp[0];

				temp[1] = data[j][1];
				data[j][1] = data[j + 1][1];
				data[j + 1][1] = temp[1];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (sumaK < k && sumaK + data[i][0] <= k) {
			sumaK += data[i][0];
			sumaV += data[i][1];
		}
		else continue;
	}

	printf("%d", sumaV);

	return 0;
}
