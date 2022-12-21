#define _CRT_SECURE_NO_WARNINGS
#define MAX_ZNAKOVA 36
#include <stdio.h>
#include <string.h>

void Ispis(char* Ime, char* Prez);
int Sastavi(char* Ime, char* Prez, char*Ime_Prez);

int main() {
	char Ime[MAX_ZNAKOVA], Prez[MAX_ZNAKOVA], Ime_Prez[MAX_ZNAKOVA] = "";
	char* pIme_Prez = Ime_Prez;

	printf("Unesi ime ");
	scanf("%[^\n]s", &Ime);

	printf("Unesi prezime ");
	scanf("\n%[^\n]s", &Prez);

	printf("%s %d\n", Ime_Prez, Sastavi(Ime, Prez, pIme_Prez));

	Ispis(Ime, Prez);

	return 0;
}

int Sastavi(char* Ime, char* Prez, char*Ime_Prez) {

	strcat(Ime_Prez, Ime);
	strcat(Ime_Prez, " ");
	strcat(Ime_Prez, Prez);
	strcat(Ime_Prez, ".");

	return (int)strlen(Ime_Prez);
}

void Ispis(char* Ime, char* Prez) {

	int size = 0;
	if (strlen(Ime) > strlen(Prez)) size = strlen(Ime);
	else size = strlen(Prez);

	printf("%s %s\n", Prez, Ime);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i; j++)
			printf(" ");
		
		if (Prez[i] > NULL) printf("%c", Prez[i]);
		else printf("\n");
		
		for (int j = 0; j < strlen(Prez); j++)
			printf(" ");

		if (Ime[i] > NULL) printf("%c\n", Ime[i]);
		else printf("\n");
	}
}
