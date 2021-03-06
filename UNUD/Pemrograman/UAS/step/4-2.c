// Cara kerja structnya

#include <stdio.h>

int indexTerakhirTerisi = 0;

typedef struct
{
    char sex;
    int age;
    int studytime;
    int absence;
    int g1;
    int g2;
    int g3;
} Mahasiswa;

Mahasiswa daftarMahasiswa[999999];

void bacaData()
{
    FILE *reader;
    reader = fopen("master.txt", "r");

    char _sex;
    int _age;
    int _studytime;
    int _absence;
    int _g1;
    int _g2;
    int _g3;

    while (!feof(reader))
    {
        fscanf(reader, "%c %d %d %d %d %d %d\n", &_sex, &_age, &_studytime, &_absence, &_g1, &_g2, &_g3);

        Mahasiswa sementara;
        sementara.sex = _sex;
        sementara.age = _age;
        sementara.studytime = _studytime;
        sementara.absence = _absence;
        sementara.g1 = _g1;
        sementara.g2 = _g2;
        sementara.g3 = _g3;

        daftarMahasiswa[indexTerakhirTerisi] = sementara;
        indexTerakhirTerisi++;
    }
}

void pilihanMenu()
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

int main()
{
    // pilihanMenu();
    bacaData();

    for (int i = 0; i < indexTerakhirTerisi; i++)
    {
        Mahasiswa x;
        x = daftarMahasiswa[i];
        printf("%c %d %d %d %d %d %d\n", x.sex, x.age, x.studytime, x.absence, x.g1, x.g2, x.g3);
    }
}