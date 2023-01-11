#define _CRT_SECURE_NO_WARNINGS
#define MAX_ZNAKOVA 350
#define MAX_RECENICA 15
#include <stdio.h>
#include <string.h>

int main() {
	FILE* file = NULL;
	char chr = ' ', recenica[MAX_RECENICA][MAX_ZNAKOVA];
	int r = 0, znak = 0, najduljaRecenica = 0;

	file = fopen("text.txt", "r");

	scanf("%c", &chr);
	
	while (!feof(file)) {

		chr = fgetc(file);
		
		if (chr != '.' && chr != '!' && chr != ':' && chr != ';' && chr != '?' && chr != ']') {
			
			recenica[r][znak] = chr;
			znak++;
		}
		else {
			fgetc(file);
			recenica[r][znak] = '\0';
			znak = 0;
			r++;
		}
	}
	
	for (int i = 0; i < r; i++) {
		if (strlen(recenica[i]) > strlen(recenica[najduljaRecenica]))
			najduljaRecenica = i;
	}

	printf("%s", recenica[najduljaRecenica]);
	fclose(file);

	return 0;
}
