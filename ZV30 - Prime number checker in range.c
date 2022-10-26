/*
Napiši program koji će ispisati sve proste brojeve od 2-N.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int n;

	scanf("%d", &n);
	
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				break;
			}
			else {
				printf("%d\n", i);
				break;
			}
		}
	}
	
	return 0;
}
