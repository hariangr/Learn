// Ini adalah comment, comment diawali dengan dua garing
// Digunakan untuk menjelaskan sesuatu dalam kode
// Tidak akan berpengaruh pada program hasil

#include <stdio.h>

// Function [main], function yang paling pertama dijalankan oleh program
int main()
{
    // Misal untuk menjelaskan fungsi sebuah variabel
    int menu;

    // Menampilkan menu
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