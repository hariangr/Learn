#include <stdio.h>

int main()
{
    int menu;

    printf("Menu\n");
    printf("> 1. Whoa\n");
    printf("> 2. Beh\n");

    printf("Masukkan menu? ");
    scanf("%d", &menu);

    if (menu == 1)
    {
        printf("Kamu memasukkan angka 1\n");
    }
    else if (menu == 2)
    {
        printf("Kamu memasukkan angka 2\n");
    }
    else
    {
        printf("Kamu memasukkan angka diluar menu\n");
    }
}