#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int brojZnamenki, binarniBroj, decimalniBroj = 0, ostatak, error = 0;

	scanf("%d", &brojZnamenki);

	if (brojZnamenki != 6 && brojZnamenki != 8) {
		printf("Broj znamenki moze biti samo 6 ili 8!");
		return 0;
	}

	if (brojZnamenki == 6) {
		
		scanf("%6d", &binarniBroj);

		ostatak = binarniBroj % 10;
		decimalniBroj += ostatak * 1;
		binarniBroj = binarniBroj / 10;

		if (ostatak != 0 && ostatak != 1) error = 1;

		ostatak = binarniBroj % 10;
		decimalniBroj += ostatak * 2;
		binarniBroj = binarniBroj / 10;

		if (ostatak != 0 && ostatak != 1) error = 1;

		ostatak = binarniBroj % 10;
		decimalniBroj += ostatak * 2 * 2;
		binarniBroj = binarniBroj / 10;

		if (ostatak != 0 && ostatak != 1) error = 1;

		ostatak = binarniBroj % 10;
		decimalniBroj += ostatak * 2 * 2 * 2;
		binarniBroj = binarniBroj / 10;

		if (ostatak != 0 && ostatak != 1) error = 1;

		ostatak = binarniBroj % 10;
		decimalniBroj += ostatak * 2 * 2 * 2 * 2;
		binarniBroj = binarniBroj / 10;

		if (ostatak != 0 && ostatak != 1) error = 1;

		ostatak = binarniBroj % 10;
		decimalniBroj += ostatak * 2 * 2 * 2 * 2 * 2;
		binarniBroj = binarniBroj / 10;

		if (ostatak != 0 && ostatak != 1) error = 1;

		if (error == 1) {
			printf("Binarne znamenke su samo 0 i 1");
			return 0;
		}

		printf("\nDecimalno: %d\nOktalno: %o\nHex: %x\n", decimalniBroj, decimalniBroj, decimalniBroj);
	}
	else if (brojZnamenki == 8) {
		
		scanf("%8d", &binarniBroj);

		binarniBroj = binarniBroj;

		ostatak = binarniBroj % 10;
		decimalniBroj += ostatak * 1;
		binarniBroj = binarniBroj / 10;

		if (ostatak != 0 && ostatak != 1) error = 1;

		ostatak = binarniBroj % 10;
		decimalniBroj += ostatak * 2;
		binarniBroj = binarniBroj / 10;

		if (ostatak != 0 && ostatak != 1) error = 1;

		ostatak = binarniBroj % 10;
		decimalniBroj += ostatak * 2 * 2;
		binarniBroj = binarniBroj / 10;

		if (ostatak != 0 && ostatak != 1) error = 1;

		ostatak = binarniBroj % 10;
		decimalniBroj += ostatak * 2 * 2 * 2;
		binarniBroj = binarniBroj / 10;

		if (ostatak != 0 && ostatak != 1) error = 1;

		ostatak = binarniBroj % 10;
		decimalniBroj += ostatak * 2 * 2 * 2 * 2;
		binarniBroj = binarniBroj / 10;

		if (ostatak != 0 && ostatak != 1) error = 1;

		ostatak = binarniBroj % 10;
		decimalniBroj += ostatak * 2 * 2 * 2 * 2 * 2;
		binarniBroj = binarniBroj / 10;

		if (ostatak != 0 && ostatak != 1) error = 1;

		ostatak = binarniBroj % 10;
		decimalniBroj += ostatak * 2 * 2 * 2 * 2 * 2 * 2;
		binarniBroj = binarniBroj / 10;

		if (ostatak != 0 && ostatak != 1) error = 1;

		ostatak = binarniBroj % 10;
		decimalniBroj += ostatak * 2 * 2 * 2 * 2 * 2 * 2 * 2;
		binarniBroj = binarniBroj / 10;

		if (ostatak != 0 && ostatak != 1) error = 1;

		if (error == 1) {
			printf("Binarne znamenke su samo 0 i 1");
			return 0;
		}

		printf("\nDecimalno: %d\nOktalno: %o\nHex: %x\n", decimalniBroj, decimalniBroj, decimalniBroj);
	}

	return 0;
}
