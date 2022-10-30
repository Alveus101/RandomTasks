/*
Napiši program koji će učitati rečenicu (maks. 255 znakova), te ispisuje koliko
ima malih, a koliko velikih slova engleske abecede.
*/

#define MAX_ZNAKOVA 255
#include <stdio.h>

int main()
{
    char recenica[MAX_ZNAKOVA];
    int kolicinaMalih = 0, kolicinaVelikih = 0;

    gets_s(recenica);
        
    for (int i = 0; i < MAX_ZNAKOVA; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            if (recenica[i] == j) {
                kolicinaMalih++;
                break;
            }
        }
        for (int j = 'A'; j <= 'Z'; j++) {
            if (recenica[i] == j) {
                kolicinaVelikih++;
                break;
            }
        }
    }

    printf("Recenica ima %d malih i %d velikih slova.", kolicinaMalih, kolicinaVelikih);

    return 0;
}
