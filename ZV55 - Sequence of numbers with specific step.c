/*
Napiši funkciju koja ispisuje aritmetički niz od člana A do člana B sa razmakom
D. Prototip funkcije glasi: void niz(int a, int b, int d);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void niz(int a, int b, int d){
	for (int i = a; i <= b; i++) {
		if (i % d == 0)
			printf("%d\n", i);
	}
}

int main()
{
	int a, b, d;
	printf("Clan A: ");
	scanf("%d", &a);
	printf("Clan B: ");
	scanf("%d", &b);
	printf("Clan D: ");
	scanf("%d", &d);

	niz(a, b, d);
	
	return 0;
}
