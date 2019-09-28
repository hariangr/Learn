#include <stdio.h>
#include <stdlib.h>

// n = 3
//  *    << baris 1, bintang 1, spasi kiri 2, spasi kanan 2, spasi 4
// ***   << baris 2, bintang 3, spasi kiri 1, spasi kanan 1, spasi 2
//*****  << baris 3, bintang 5, spasi kiri 0, spasi kanan 0, spasi 0

// Jumlah bintang di baris terakhir = n*2-1 

// (Jumlah bintang terbanyak - Jumlah bintang di baris saat ini)/2
int main() {
    int n = 9;

    int bintangTerbanyak = n*2-1;

    for (int i = 1; i <= n; i++)
    {
        // Bertanggung jawab untuk spasi sebelah kiri
        for (int k = 0; k < (bintangTerbanyak - (i * 2 -1))/ 2; k++)
        {
            printf(" ");
        }
        // Sampai sini

        // Bertanggung jawab untuk bintang
        for (int j = 0; j < (i*2-1); j++)
        {
            printf("*");
        }
        // Sampai sini

        // Bertanggung jawab untuk nekan tombol 'Enter'
        printf("\n");
        // Sampai sini
    }
    

    return 0;
}