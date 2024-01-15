/*
Zadatak: 
Jakov je na poslu dobio zadatak provjeravati logove i brojati koliko se puta neka znamenka z u njima pojavljuje. Logovi su organizirani tako da se pamte samo zadnja 4 retka teksta unesena s tipkovnice.  
Jakovu je dosadilo ručno brojati koliko se puta pojavila tražena zamenka te Vas je zamolio da mu pomognete. Treba mu program koji od korisnika traži unos znamenke z i zatim niz redaka teksta. 

Program uvijek pamti samo 4 posljednja retka teksta i unutar posebne funkcije trazi prebrojava koliko se puta tražena znamenka pojavljuje u trenutnim logovima. 
Nakon svakog novog unesenog retka, glavni program ispisuje novi broj pojave znamenke. Program završava unosom stringa END.

TC #1
2
INFO:root:Started process 1
INFO:root:Started process 2
INFO:root:Started process 3
END

0
1
1


TC#2
2
INFO:root:Started process 1
INFO:root:Started process 2
INFO:root:Started process 3
WARNING:root:Unauthorized changes in process 3
WARNING:42 alarms active
INFO:sector_1:open gate 12
END


0
1
1
1
2
2


TC#3
3
INFO:root:Started process 1
WARNING:33 alarms active
INFO:root:Started process 2
ERROR:Unauthorized access
INFO:root:Ended process 2
WARNING:37 alarms active
INFO:root:Started process 3
WARNING:root:Unauthorized changes in process 3
INFO:root:Ended process 3
WARNING:42 alarms active
INFO:sector_1:open gate 12
END


0
2
2
2
2
1
2
3
4
3
2
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAMCENJE 4
#define MAX_LOG 100


int trazi(int z, char logovi[PAMCENJE][MAX_LOG]) {
	int count = 0;
	char number_str = '0' + (char)z;

	for (int i = 0; i < PAMCENJE; i++) {
		for (int j = 0; j < strlen(logovi[i]); j++) {
			if (logovi[i][j] == number_str)
				count++;
		}
	}

	return count;
}


int main() {
	int z = 0;
	char logovi[PAMCENJE][MAX_LOG], input[MAX_LOG];

	scanf("%d\n", &z);

	while (strcmp(input, "END") != 0) {
		scanf("%100[^\n]%*c", input);

		if (strcmp(input, "END") == 0) break;

		for (int i = 0; i < PAMCENJE-1; i++) {
			strcpy(logovi[i], logovi[i+1]);
		}

		strcpy(logovi[3], input);

		printf("%d\n", trazi(z, logovi));
	}

	return 0;
}
