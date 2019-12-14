#include <stdio.h>

int main()
{
    int angka;
    angka = 5;

    printf("%d\n", angka);

    printf("Masukkan nilai angka yang baru? ");
    scanf("%d", &angka);

    printf("%d\n", angka);
}