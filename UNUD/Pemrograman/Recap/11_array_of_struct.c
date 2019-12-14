// Anggap struct itu seperti entitas dalam KBD
// Lalu isi dari struct itu seperti atribut dalam KBD

// Buat struct dengan nama Orang

#include <stdio.h>
#include <string.h>

struct Orang
{
    char nama[100];
    int umur;
    char jenis_kelamin;
};

void printDetilOrang(struct Orang o) {
    printf("Nama adalah: %s\n", o.nama);
    printf("Umur adalah: %d\n", o.umur);
    printf("Jenis kelamin adalah: %d\n", o.jenis_kelamin);
}

int main()
{
    struct Orang kusuma;
    strcpy(kusuma.nama, "Ni Kusuma Siapa Kaden");
    kusuma.umur = 10;
    kusuma.jenis_kelamin = 'M';

    struct Orang dwi;
    strcpy(dwi.nama, "Ni Dwi Satrio Tak Kashiapa");
    dwi.umur = -1;
    dwi.jenis_kelamin = 'F';

    printDetilOrang(kusuma);
    printf("\n");
    printDetilOrang(dwi);
}