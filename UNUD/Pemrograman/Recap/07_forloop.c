// Baca "6_whileloop.c" terlebih dahulu
//
// Bentuk pada modul 6 dapat ditulis dengan lebih singkat menjadi sebuah for loop
// For loop hanya bentuk lebih pendek dari while loop

#include <stdio.h>

int main()
{
    // For loop terdiri dari 3 bagian yang dipisahkan dengan tanda titik koma (;)
    // Bagian pertama adalah deklarasi dan nilai awal dari variabel
    // Bagian kedua adalah kondisi, selama kondisi itu terpenuhi, lanjutkan perulangan
    // Bagian ketiga adalah manipulasi, bagaiamna memanipulasi variabel x
    // x++ itu sama artinya dengan x = x + 1
    // x-- itu sama artinya dengan x = x - 1
    for (int x = 0; x < 10; x++)
    {
        printf("%d\n", x);
    }
}