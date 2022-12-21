#define _CRT_SECURE_NO_WARNINGS
#define MAX_ZNAKOVA 100
#include <stdio.h>
#include <string.h>

int prebrojiMalaSlova(char unos[]) {
	int counter = 0;

	for (int i = 0; i < strlen(unos); i++) {
		if (unos[i] >= 'a' && unos[i] <= 'z')
			counter++;
		if ((unos[i] == 'l' && unos[i + 1] == 'j') || (unos[i] == 'n' && unos[i + 1] == 'j'))
			counter--;
	}
	return counter;
}

int main() {
	char unos[MAX_ZNAKOVA];

	scanf("%[^\n]s", &unos);

	printf("%d", prebrojiMalaSlova(unos));

	return 0;
}

/*
Test case #1
Ulaz:
BoK! KaKo SI? Ja SAM supEEEr.

Izlaz:
8

Test case #2
Ulaz:
365 JE PROSLO dana. BEZ tebe BOLJE SAM! UZALUD me ZOVES.

Izlaz:
10
*/
