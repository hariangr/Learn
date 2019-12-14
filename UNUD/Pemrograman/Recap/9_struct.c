// Anggap struct itu seperti entitas dalam KBD
// Lalu isi dari struct itu seperti atribut dalam KBD

// Buat struct dengan nama Orang

#include <stdio.h>
#include <string.h>

struct Orang
{
    // Atribut pertama adalah nama
    char nama[100];

    // Atribut kedua adalah umur
    int umur;

    // Atribut ketiga adalah jenis_kelamin; F untuk perempuan dan M untuk laki-laki
    char jenis_kelamin;
};

int main()
{
    // Untuk membuat sebuah variabel dengan tipe struct Orang
    // Buat sebuah variabel dengan nama kusuma
    struct Orang kusuma;

    // Untuk mengakses atribut dari sebuah struct digunakan notasi dot
    // nama_variabel.nama_atribut

    // Untuk menyetel nama dari variabel kusuma
    // Karena ini string, bakalan agak susah...
    // Lihat nanti kubikin modul khusus string :P
    strcpy(kusuma.nama, "Ni Kusuma Siapa Kaden");

    // Untuk menyetel umur dari kusuma
    kusuma.umur = 10;

    // Untuk menyetel jenis_kelamin dari kusuma
    kusuma.jenis_kelamin = 'M';

    printf("Nama adalah: %s\n", kusuma.nama);
    printf("Umur adalah: %d\n", kusuma.umur);
    printf("Jenis kelamin adalah: %d\n", kusuma.jenis_kelamin);
}

// PS. Nulis gini pas Build IT susah juga ternyata