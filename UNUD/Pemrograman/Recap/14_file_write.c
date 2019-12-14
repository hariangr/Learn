#include <stdio.h>

// Ini sebuah procedure untuk menulis ke file bernama 14_file_write_data.txt di folder yang sama
void tulisInfoOrangKeFile(char nama[100], char jenis_kelamin, int umur)
{
    // Deklarasikan sebuah pointer bernama writer
    FILE *writer;

    // Inisiasi writer dengan function fopen
    // "a" dibelakang itu artinya append, setiap nulis sesuatu akan menulis ke baris terakhir
    writer = fopen("14_file_write_data.txt", "a");

    // fprintf itu mirip kayak printf, cuma disimpen ke file bukan ke layar
    fprintf(writer, "%s;%c;%d\n", nama, jenis_kelamin, umur);
}

int main()
{
    // Apa guna fflush? Sama aku juga bingung :P

    char nama[100];
    fflush(stdin);
    printf("Nama orang? ");
    scanf("%s", &nama[0]);

    char jenis_kelamin;
    fflush(stdin);
    printf("Jenis kelamin? ");
    scanf("%c", &jenis_kelamin);

    int angka;
    fflush(stdin);
    printf("Umur? ");
    scanf("%d", &angka);

    tulisInfoOrangKeFile(nama, jenis_kelamin, angka);
}