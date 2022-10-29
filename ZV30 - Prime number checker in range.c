/*
Napiši program koji će ispisati sve proste brojeve od 2-N.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int n, found = 0;

	scanf("%d", &n);

	for (int j = 2; j <= n; j++) {
		for (int i = 2; i < j; i++) {
			if (j % i == 0) {
				found = 1;
			}
			else {
				continue;
			}
		}
		if (found == 1) {
			found = 0;
		}
		else printf("%d, ", j);
	}
	
	return 0;
}
