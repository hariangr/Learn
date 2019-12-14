// Sebuah variabel dapat menyimpan satu nilai
// Misal variabel int x = 10; hanya bisa menyimpan satu nilai yaitu angka 10
// Array digunakan untuk menyimpan lebih dari satu nilai dalam sebuah variabel
// Diakses menggunakan posisinya yang akan disebut sebagai index
// Index dimulai dari 0 untuk posisi paling pertama

#include <stdio.h>

int main()
{
    // Int adalah tipe data dari data-data yang disimpan di dalam array [arr]
    // 10 adalah jumlah datanya
    int arr[10] = {22, 56, 32, 5, 6, 7, 8, 987, 55, 10};

    for (int i = 0; i < 10; i++)
    {
        // Cara mengakses nilai dalam sebuah array adalah menggunakan kurung siku ( [] )
        // Misal untuk mengakses item pertama dari array arr, gunakan arr[0]
        printf("%d\n", arr[i]);
    }
}