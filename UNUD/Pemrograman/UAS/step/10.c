// Tambahkan menu mencari nilai rata-rata G1, G2, G3

#include <stdio.h>
#include <stdlib.h>

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

    // Lewati header file csv
    char skip[100];
    fscanf(pembaca, "%s %s %s %s %s %s %s\n", &skip[0], &skip[0], &skip[0], &skip[0], &skip[0], &skip[0], &skip[0]);

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

    printf("> Sejumlah %d data berhasil ditampilkan\n", indexTerakhirTerisi + 1);
}

void menu2ImportData()
{
    printf("Masukkan path dari file yang ingin di import? \n");
    char lokasiFile[255];
    printf(">> (next1.txt) ");
    scanf("%s", &lokasiFile[0]);

    FILE *pembaca;
    pembaca = fopen(lokasiFile, "r");

    int indexTerakhirSebelumImport = indexTerakhirTerisi;

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

    printf("> Sejumlah %d data berhasil di import\n", indexTerakhirTerisi - indexTerakhirSebelumImport + 1);
    printf("> Untuk mengupdate file master.txt silahkan kembali ke menu awal\n");
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

void menuPrintSortedBesarKeKecil()
{
    Mahasiswa result[indexTerakhirTerisi + 1];
    for (int i = 0; i <= indexTerakhirTerisi; i++)
    {
        result[i] = daftarMahasiswa[i];
    }

    while (1 > 0)
    {
        int counter = 0;

        for (int i = 0; i <= indexTerakhirTerisi - 1; i++)
        {
            if (result[i].g3 < result[i + 1].g3)
            {
                Mahasiswa temp = result[i + 1];
                result[i + 1] = result[i];
                result[i] = temp;
                counter++;
            }
        }

        if (counter == 0)
        {
            break;
        }
    }

    int indexTerakhirPrint;
    if (indexTerakhirTerisi > 20)
    {
        indexTerakhirPrint = 19;
    }
    else
    {
        indexTerakhirPrint = indexTerakhirTerisi;
    }

    for (int i = 0; i <= indexTerakhirPrint; i++)
    {
        Mahasiswa x = result[i];
        printf("%c %d %d %d %d %d %d\n", x.sex, x.age, x.studytime, x.absence, x.g1, x.g2, x.g3);
    }
}

void menuPrintSortedKecilKeBesar()
{
    Mahasiswa result[indexTerakhirTerisi + 1];
    for (int i = 0; i <= indexTerakhirTerisi; i++)
    {
        result[i] = daftarMahasiswa[i];
    }

    while (1 > 0)
    {
        int counter = 0;

        for (int i = 0; i <= indexTerakhirTerisi - 1; i++)
        {
            if (result[i].g3 > result[i + 1].g3)
            {
                Mahasiswa temp = result[i + 1];
                result[i + 1] = result[i];
                result[i] = temp;
                counter++;
            }
        }

        if (counter == 0)
        {
            break;
        }
    }

    int indexTerakhirPrint;
    if (indexTerakhirTerisi > 20)
    {
        indexTerakhirPrint = 19;
    }
    else
    {
        indexTerakhirPrint = indexTerakhirTerisi;
    }

    for (int i = 0; i <= indexTerakhirPrint; i++)
    {
        Mahasiswa x = result[i];
        printf("%c %d %d %d %d %d %d\n", x.sex, x.age, x.studytime, x.absence, x.g1, x.g2, x.g3);
    }
}

void menu5PrintSorted()
{
    printf("Tampilkan 20 pemilik G3\n");
    printf("> 1. 20 Pemilik G3 teratas\n");
    printf("> 2. 20 Pemilik G3 terbawah\n");
    printf(">> Masukkan menu yang dipilih? ");

    int menu;
    scanf("%d", &menu);

    if (menu == 1)
    {
        menuPrintSortedBesarKeKecil();
    }
    else if (menu == 2)
    {
        menuPrintSortedKecilKeBesar();
    }
    else
    {
        printf("Error");
    }
}

void menu6TulisMaster()
{
    FILE *penulis;
    penulis = fopen("master.txt", "w");

    // Menulis header
    fprintf(penulis, "sex age studytime absences G1 G2 G3\n");

    for (int i = 0; i <= indexTerakhirTerisi; i++)
    {
        Mahasiswa x;
        x = daftarMahasiswa[i];

        fprintf(penulis, "%c %d %d %d %d %d %d\n", x.sex, x.age, x.studytime, x.absence, x.g1, x.g2, x.g3);
    }

    printf("%d berhasil ditulis ke master.txt\n", indexTerakhirTerisi + 1);
    fclose(penulis);
}

void menu7CariRata()
{
    int menu;
    printf("Mencari nilai rata rata\n");
    printf("> 1. G1\n");
    printf("> 2. G2\n");
    printf("> 3. G3\n");
    printf(">> Pilih rata-rata yang ingin dicari? ");
    scanf("%d", &menu);

    if (menu < 1 || menu > 3)
    {
        printf("Error\n");
        return;
    }

    int totalNilai = 0;
    for (int i = 0; i <= indexTerakhirTerisi; i++)
    {
        if (menu == 1)
        {
            totalNilai = totalNilai + daftarMahasiswa[i].g1;
        }
        else if (menu == 2)
        {
            totalNilai = totalNilai + daftarMahasiswa[i].g2;
        }
        else if (menu == 3)
        {
            totalNilai = totalNilai + daftarMahasiswa[i].g3;
        }
    }

    double rata = (double)totalNilai / (double)(indexTerakhirTerisi + 1);
    printf("Rata-rata G%d adalah %lf\n", menu, rata);
}

void pilihanMenu()
{
    printf("============================\n");
    printf("[UAS]\n");
    printf("> 1. Tampilkan semua data tersimpan\n");
    printf("> 2. Import data dari sebuah file\n");
    printf("> 3. Export data laki-laki\n");
    printf("> 4. Export data perempuan\n");
    printf("> 5. Tampilkan 20 data GP3\n");
    printf("> 6. Perbarui file master.txt\n");
    printf("> 7. Cari nilai rata-rata\n");
    printf("> 0. Keluar\n");
    printf(">> Pilih menu? ");

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
        menu5PrintSorted();
        break;
    case 6:
        menu6TulisMaster();
        break;
    case 7:
        menu7CariRata();
        break;
    case 0:
        exit(0);
        break;
    default:
        printf("Error\n");
        break;
    }

    // Pake rekursif
    char lagi;
    printf("Kembali ke menu awal? (y/n)\n");
    printf(">> ");
    fflush(stdin);
    scanf("%c", &lagi);

    if (lagi == 'Y' || lagi == 'y')
    {
        pilihanMenu();
    }
}

int main()
{
    bacaData();

    pilihanMenu();
}