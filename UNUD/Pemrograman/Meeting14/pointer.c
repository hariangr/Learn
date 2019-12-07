#include <stdio.h>

void cetak(int angka)
{
    int apakek = angka * angka * 2;
    printf("angka yg kamu suruh aku nulis %d\n", apakek);
}

void cetakPointer(int *angkaPtr)
{
    printf("pointer yg kamu suruh aku nulis %d\n", *angkaPtr);
}

int main(int argc, char const *argv[])
{
    // cetak(9);

    int sesuatu = 3;
    cetakPointer(&sesuatu);

    // int a = 10;
    // int *aPtr = &a;

    // printf("%d\n", a); // Mencari nilai dari variabel a (10)

    // printf("%d\n", aPtr); // Memprint isi variabel aPtr, yaitu &a, yaitu alamat variabel a
    // printf("%d\n", &a);   // Memprint alamat variabel a

    // printf("%d\n", *aPtr); // Mencari isi nilai yang disimpen di pointer aPtr
    // printf("%d\n", *&*&a); // Ribet (Baca dari kanan ke kiri)

    return 0;
}
