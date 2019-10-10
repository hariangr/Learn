#include <stdio.h>
int phi = 314;

int main()

{
    int angka, jumlah = 1;
    int input;
    printf("Masukkan bilangan:");
    scanf("%d", &input);
    printf("%d! = ", input);

    for (angka = input; angka >= 1; angka = angka - 1)
    {
        jumlah = jumlah * angka;
        printf("%d ", angka);
        if (angka != 1)
        {
            printf("x ");
        }
    }
    printf("= %d", jumlah);
}