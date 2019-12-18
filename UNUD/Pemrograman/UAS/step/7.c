// Cara kerja menu 3 dan 4

#include <stdio.h>

int indexTerakhirTerisi = -1;

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
    FILE *pembaca;
    pembaca = fopen("master.txt", "r");

    char _sex;
    int _age;
    int _studytime;
    int _absence;
    int _g1;
    int _g2;
    int _g3;

    while (!feof(pembaca))
    {
        indexTerakhirTerisi++;
        fscanf(pembaca, "%c %d %d %d %d %d %d\n", &_sex, &_age, &_studytime, &_absence, &_g1, &_g2, &_g3);

        Mahasiswa sementara;
        sementara.sex = _sex;
        sementara.age = _age;
        sementara.studytime = _studytime;
        sementara.absence = _absence;
        sementara.g1 = _g1;
        sementara.g2 = _g2;
        sementara.g3 = _g3;

        daftarMahasiswa[indexTerakhirTerisi] = sementara;
    }
}

void menu1TampilkanSemuaData()
{
    printf("Menu pertama\n");

    for (int i = 0; i <= indexTerakhirTerisi; i++)
    {
        Mahasiswa x;
        x = daftarMahasiswa[i];
        printf("%c %d %d %d %d %d %d\n", x.sex, x.age, x.studytime, x.absence, x.g1, x.g2, x.g3);
    }
}

void menu2ImportData()
{
    printf("Masukkan path dari file yang ingin di import? \n");
    char lokasiFile[255];
    scanf("%s", &lokasiFile[0]);

    FILE *pembaca;
    pembaca = fopen(lokasiFile, "r");

    char _sex;
    int _age;
    int _studytime;
    int _absence;
    int _g1;
    int _g2;
    int _g3;

    while (!feof(pembaca))
    {
        indexTerakhirTerisi++;
        fscanf(pembaca, "%c %d %d %d %d %d %d\n", &_sex, &_age, &_studytime, &_absence, &_g1, &_g2, &_g3);

        Mahasiswa sementara;
        sementara.sex = _sex;
        sementara.age = _age;
        sementara.studytime = _studytime;
        sementara.absence = _absence;
        sementara.g1 = _g1;
        sementara.g2 = _g2;
        sementara.g3 = _g3;

        daftarMahasiswa[indexTerakhirTerisi] = sementara;
    }
}

void menu3ExportLaki()
{
    FILE *penulis;
    penulis = fopen("male.txt", "w");

    for (int i = 0; i <= indexTerakhirTerisi; i++)
    {
        Mahasiswa x;
        x = daftarMahasiswa[i];

        if (x.sex == 'M')
        {
            fprintf(penulis, "%c %d %d %d %d %d %d\n", x.sex, x.age, x.studytime, x.absence, x.g1, x.g2, x.g3);
        }
    }

    fclose(penulis);
}

void menu4ExportPerempuan()
{
    FILE *penulis;
    penulis = fopen("female.txt", "w");

    for (int i = 0; i <= indexTerakhirTerisi; i++)
    {
        Mahasiswa x;
        x = daftarMahasiswa[i];

        if (x.sex == 'F')
        {
            fprintf(penulis, "%c %d %d %d %d %d %d\n", x.sex, x.age, x.studytime, x.absence, x.g1, x.g2, x.g3);
        }
    }

    fclose(penulis);
}

void pilihanMenu()
{
    printf("[MENU SELECTION]\n");
    printf("> 1. Tampilkan semua data tersimpan\n");
    printf("> 2. Import data dari sebuah file\n");
    printf("> 3. Export data laki-laki\n");
    printf("> 4. Export data perempuan\n");
    printf("> 5. Tampilkan 20 data GP3\n");
    printf("> 6. Keluar\n");

    int menu;
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        menu1TampilkanSemuaData();
        break;
    case 2:
        menu2ImportData();
        break;
    case 3:
        menu3ExportLaki();
        break;
    case 4:
        menu4ExportPerempuan();
        break;
    case 5:
        printf("Menu kelima");
        break;
    case 6:
        // TODO: Belum diimplementasi
        break;
    default:
        printf("Error\n");
        break;
    }
}

int main()
{
    bacaData();

    while (1 > 0)
    {
        pilihanMenu();
    }
}