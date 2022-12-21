#define _CRT_SECURE_NO_WARNINGS
#define MAX_ZNAKOVA 100
#include <stdio.h>
#include <string.h>

int suglasnici(char unos[]) {
	int counter = 0, found = 0;
	char samoglasnici[] = { 'a', 'e', 'i', 'o', 'u', ' ', '!', '.', '?' };

	_strlwr(unos);

	for (int i = 0; i < strlen(unos); i++) {
		for (int j = 0; j < sizeof(samoglasnici); j++) {
			if (unos[i] == samoglasnici[j] || ( unos[i] >= '0' && unos[i] <= '9' ) ) {
				found = 1;
				break;
			}
		}
		if ((unos[i] == 'l' && unos[i + 1] == 'j') || (unos[i] == 'n' && unos[i + 1] == 'j')) counter--;
		if (!found) counter++;
		found = 0;
	}
	return counter;
}

int main() {
	char unos[MAX_ZNAKOVA];

	scanf("%[^\n]s", &unos);
	printf("%d", suglasnici(unos));

	return 0;
}
