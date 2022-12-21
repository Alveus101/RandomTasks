#define _CRT_SECURE_NO_WARNINGS
#define MAX_ZNAKOVA 100
#include <stdio.h>
#include <string.h>

int suglasnici(char unos[]) {
	int counter = 0;

	_strlwr(unos);

	for (int i = 0; i < strlen(unos); i++) {
		if ( unos[i] > '9' && unos[i] != 'a' && unos[i] != 'e' && unos[i] != 'i' && unos[i] != 'o' && unos[i] != 'u' && unos[i] != ' ' && unos[i] != '!' && unos[i] != '.' && unos[i] != '?') {
			counter++;
			if ((unos[i] == 'l' && unos[i + 1] == 'j') || (unos[i] == 'n' && unos[i + 1] == 'j')) 
				counter--;
		}
	}
	return counter;
}

int main() {
	char unos[MAX_ZNAKOVA];

	scanf("%[^\n]s", &unos);
	printf("%d", suglasnici(unos));

	return 0;
}
