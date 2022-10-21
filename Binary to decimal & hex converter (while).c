#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int brojZnamenki, binarniBroj, decimalniBroj = 0, ostatak, potencija = 1;

	scanf("%d", &brojZnamenki);

	if (brojZnamenki != 6 && brojZnamenki != 8) {
		printf("Broj znamenki moze biti samo 6 ili 8!");
		return 0;
	}

	if (brojZnamenki == 6) 
		scanf("%6d", &binarniBroj);
	else if (brojZnamenki == 8)
		scanf("%8d", &binarniBroj);
	
	while (binarniBroj > 0) {
		ostatak = binarniBroj % 10;
		decimalniBroj += ostatak * potencija;
		binarniBroj /= 10;
		potencija *= 2;
	}

	printf("\nDecimalno: %d\nOktalno: %o\nHex: %x\n", decimalniBroj, decimalniBroj, decimalniBroj);

	return 0;
}