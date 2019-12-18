// Pemilihan menu

#include <stdio.h>

int main()
{
    printf("[MENU SELECTION]\n");
    printf("> 1. Tampilkan semua data tersimpan\n");
    printf("> 2. Import data dari sebuah file\n");
    printf("> 3. Export data laki-laki\n");
    printf("> 4. Export data perempuan\n");
    printf("> 5. Tampilkan 20 data GP3\n");

    int menu;
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        printf("Menu pertama");
        break;
    case 2:
        printf("Menu kedua");
        break;
    case 3:
        printf("Menu ketiga");
        break;
    case 4:
        printf("Menu keempat");
        break;
    case 5:
        printf("Menu kelima");
        break;
    default:
        printf("Error\n");
        break;
    }
}