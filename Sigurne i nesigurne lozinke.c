/*
Zadatak: https://github.com/Alveus101/RandomTasks/blob/main/Other/Auditorne%206%20-%20Sigurne%20i%20nesigurne%20lozinke.pdf
File common_passwords: https://github.com/Alveus101/RandomTasks/blob/main/Other/common_passwords.txt
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_INPUT 100
#define MAX_COMM_PASS 100
#define MAX_USERS 10

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <string.h>

struct podaci {
	char username[MAX_INPUT];
	char password[MAX_INPUT];
	int isSecure;
};

int isCommon(podaci * user, FILE* checkFile, int i) {
	int found = FALSE;
	char common_pass[MAX_COMM_PASS] = "";

	rewind(checkFile);

	while (!feof(checkFile)) {

		fscanf(checkFile, "%[^\n]%*c", common_pass);
		if (strcmp(user[i].password, common_pass) == 0) {
			found = TRUE;
			break;
		}
		else if (strncmp(user[i].password, user[i].username, 5) == 0) {
			found = TRUE;
			break;
		}
	}

	return found;
}

int main() {

	FILE* fin = NULL, *fout = NULL;
	podaci user[MAX_USERS] = {"","", 0};
	char input[MAX_INPUT * 2];
	int i = 0;

	fin = fopen("common_passwords.txt", "r");
	fout = fopen("RezultatiAnalize.txt", "w");

	while (strcmp(input, ":") != 0) {
		
		scanf("%s", input);
		sscanf(input,"%[^:]:%[^\n]", &user[i].username, &user[i].password);

		//printf("%s\n", user[i].password);
		fprintf(fout, "%s\n", user[i].password);

		if (!isCommon(user, fin, i))
			user[i].isSecure = TRUE;

		i++;
	}
		
	fprintf(fout, "Popis sigurnih lozinki:\n");
	printf("Popis sigurnih lozinki:\n");

	for (int j = 0; j < i; j++) {
		if (user[j].isSecure == TRUE) {
			//printf("%s\n", user[j].password);
			fprintf(fout, "%s\n", user[j].password);
		}
	}
	return 0;
}
