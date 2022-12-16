/*
Napiši program koji će učitati prirodan broj N (max. 50) i isto toliko pozitivnih
cjelih brojeva. Program učitane brojeve treba ispisati od najmanjeg prema
najvećem.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 50
#include <stdio.h>

int main()
{
    int n, temp = 0, niz[MAX];

    scanf("%d", &n);

    if (n > 50) {
        printf("'N' moze biti maksimalno 50!");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &niz[i]);
    }

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (niz[j] > niz[j + 1]) {
                temp = niz[j];
                niz[j] = niz[j + 1];
                niz[j + 1] = temp;
            }
       }
    }
   
    printf("\n");

    for (int i = 0; i < n; i++ ) {
        printf("%d\n", niz[i]);
    }

    return 0;
}
