#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct BukuModel
{
    char id[3];
    char jenis[50];
    char judul[50];
};

struct BukuModel bukuTersedia[5];

void clearScreen()
{
    system("cls||clear");
}

int getIndexByBookId(char _id[3])
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(_id, bukuTersedia[i].id) == 0)
        {
            return i;
        }
    }

    return -1;
}

bool cekIdSudahAda(char _id[3])
{
    int _index = getIndexByBookId(_id);

    if (_index == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void tambahBukuTersedia(int _index, char _id[3], char _jenis[50], char _judul[50])
{
    struct BukuModel _buku;
    strcpy(_buku.id, _id);
    strcpy(_buku.jenis, _jenis);
    strcpy(_buku.judul, _judul);

    bukuTersedia[_index] = _buku;
}

void loadDummyData()
{
    tambahBukuTersedia(0, "A1", "Pemrograman", "Trick for C++");
    tambahBukuTersedia(1, "A2", "Sastra Jepang", "Katakana & Kanji 2");
    tambahBukuTersedia(2, "A3", "Teknologi", "Cisco Networking");
    tambahBukuTersedia(3, "A4", "Matematika", "Statistika jilid 2");
    tambahBukuTersedia(4, "A5", "Sains & physics", "Anatomi Tubuh  Manusia");
}

void printSemuaBukuTersedia()
{
    printf("INDEX\tKODE\tJENIS\tJUDUL\n");

    for (int i = 0; i < 5; i++)
    {
        struct BukuModel _buku = bukuTersedia[i];
        printf("%d \t%s \t%s \t%s \n", i, _buku.id, _buku.jenis, _buku.judul);
    }
}

void printSyaratKetentuan()
{
    printf("----------------------------------------------------------------\n");
    printf("|                Syarat Dan Ketentuan:                         |\n");
    printf("----------------------------------------------------------------\n");
    printf("| 1. Diharap Mengisi Data Peminjaman Buku                      |\n");
    printf("| 2. Apabila Terlambat Mengembalikan Buku Akan Dikenakan Denda |\n");
    printf("----------------------------------------------------------------\n");
}

void menuDaftarMember()
{
    FILE *in = fopen("data_member.txt", "r");
    if (!in)
    {
        printf("tidak ada file");
    }
    else
    {
        int i = 0;
        while (!feof(in))
        {
            char nama_member[20];
            char alamat_member[20];
            char ttl_member[2][10][4];
            char pekerjaan_member[20];
            fscanf(in, "%[^#]#%[^#]#%[^#]#%s\n", &nama_member, &alamat_member, &ttl_member, &pekerjaan_member);
            fflush(stdin);
            printf("%d.  Nama      : %s", i + 1, nama_member);
            printf("\n   Alamat    : %s", alamat_member);
            printf("\n   TTL       : %s", ttl_member);
            printf("\n   Pekerjaan : %s\n\n", pekerjaan_member);
            i++;
        }
        fclose(in);
        printf("Jumlah Member : %d\n", i);
    }
}

void menuBuatMember()
{
    printf("========================================\n");
    printf("|       ***Membuat Member Baru***      |\n");
    printf("========================================\n");

    char nama_member[20];
    printf("Nama      : ");
    fflush(stdin);
    scanf("%[^\n]s", &nama_member);

    char alamat_member[20];
    printf("\nAlamat    : ");
    fflush(stdin);
    scanf("%[^\n]s", &alamat_member);

    char ttl_member[2][10][4];
    printf("\nTTL       : ");
    fflush(stdin);
    scanf("%[^\n]s", &ttl_member);

    char pekerjaan_member[20];
    printf("\nPekerjaan : ");
    fflush(stdin);
    scanf("%[^\n]s", &pekerjaan_member);
    clearScreen();

    FILE *datamember = fopen("data_member.txt", "a");

    int m = 1; // INI variabel m UNTUK APA?
    fprintf(datamember, "%s#%s#%s#%s#%d\n", nama_member, alamat_member, ttl_member, pekerjaan_member, m);
    fclose(datamember);

    printf("Sukses menambah data member.\n");
    getchar();
    clearScreen();

    printf("=============================================\n");
    printf("|==== * Kartu Member Perpustakaan * ====|\n");
    printf("=============================================");
    printf("\n|         Nama      : %s             ", nama_member);
    printf("\n|         Alamat    : %s             ", alamat_member);
    printf("\n|         TTL       : %s             ", ttl_member);
    printf("\n|         Pekerjaan : %s             ", pekerjaan_member);
    printf("\n=============================================\n");
    printf("|* Terima kasih %s Telah Bergabung *|\n", nama_member);
    printf("=============================================\n");
}

menuPinjamBuku()
{
    printf("===============================================================\n");
    printf("=                                                             =\n");
    printf("=                  DAFTAR BUKU PERPUSTAKAAN                   =\n");
    printf("=                                                             =\n");
    printf("===============================================================\n\n");
    printf("---------------------------------------------------------------\n");
    printf("|   KODE BUKU   |     JENIS BUKU      |        JUDUL BUKU     |\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < 5; i++)
    {
        struct BukuModel _buku = bukuTersedia[i];
        printf("|\t%s\t|\t%s\t|\t%s\t|\n", _buku.id, _buku.jenis, _buku.judul);
    }

    printf("---------------------------------------------------------------\n\n");

    char nama_penyewa_buku[20];
    printf("Nama Penyewa Buku    : ");
    scanf("%[^\n]s", &nama_penyewa_buku);

    int jumlah_peminjaman;
    do
    {
        printf("Jumlah Jenis Buku yang Ingin Dipinjam [max 5]    : ");
        scanf("%d", &jumlah_peminjaman);
        if ((jumlah_peminjaman > 5) || (jumlah_peminjaman < 1))
        {
            printf("Jumlah jenis buku maximal 5. Silahkan ulangi kembali\n");
        }
    } while ((jumlah_peminjaman > 5) || (jumlah_peminjaman < 1));

char  kode[5][3]
    if ((jumlah_peminjaman <= 5) && (jumlah_peminjaman >= 1))
    {
        while (i <= jumlah_peminjaman)
        {
            printf("\n=======================================\n");
            printf("| buku ke-%d \n", i);
            printf("| Kode Buku                 : ");
            scanf("%s", &kode[i]);
            if (cek(kode[i]) == true)
            {
                printf("| Jumlah Buku yang Dipinjam : ");
                scanf("%d", &jumlah[i]);
                printf("=======================================\n");
                i++;
            }
            else
            {
                printf("Kode buku salah. Perhatikan penulisan dan silahkan ulangi kembali!");
            }
        }
    }

    //input tanggal pinjam
    printf("\nTanggal Pinjam\n");
    while (1)
    {
        printf("Tanggal [DD]   : ");
        scanf("%d", &tanggal_pinjam);
        if (tanggal_pinjam < 1 || tanggal_pinjam > 31)
        {
            printf("masukan ulang data..\n");
        }
        else
        {
            break;
        }
    }

    while (1)
    {
        printf("Bulan [MM]     : ");
        scanf("%d", &bulan_pinjam);
        if (bulan_pinjam < 1 || bulan_pinjam > 12)
        {
            printf("masukan ulang data..\n");
        }
        else
        {
            break;
        }
    }

    while (1)
    {
        printf("Tahun [YYYY]   : ");
        scanf("%d", &tahun_pinjam);
        if (tahun_pinjam < 2018)
        {
            printf("masukan ulang data..\n");
        }
        else
        {
            break;
        }
    }

    clearScreen();

    system("color D");
    printf("\nNama Penyewa Buku    : %s", nama_penyewa_buku);
    printf("\nJumlah Buku          : %d\n\n", jumlah_peminjaman);

    printf("-----------------------------------------------------------------\n");
    printf("| KODE BUKU |   JENIS BUKU   |     JUDUL BUKU     |  JUMLAH BUKU|\n");
    printf("-----------------------------------------------------------------\n");

    int i = 1;
    if (jumlah_peminjaman > 0)
    {
        while (i <= jumlah_peminjaman)
        {
            int index = getIndexByBookId(kode[i]);
            printf(" %s         %s           %s             %d  \n\n", kode[i], jenis[index], judul[index], jumlah[i]);
            i++;
        }
    }
    printf("\n\n\n\t\t*****Terima Kasih  %s Atas Kunjungan Anda!***** \n", nama_penyewa_buku);
}

void menuSelection()
{
    printf("\n======================================\n");
    printf("|       Selamat Datang Di Menu       |\n");
    printf("======================================\n");
    printf("=============Perpustakaan=============\n");
    printf("| 1. Membuat Kartu Member Perpustakaan         |\n");
    printf("| 2. Melihat Daftar Member                      |\n");
    printf("| 3. Pinjam Buku                      |\n");
    printf("| 4. Pengecekan Denda                 |\n");
    printf("| 5. Exit                            |\n");
    printf("======================================\n");
    printf("\n");
    printf("Silahkan masukan nomor menu pilihan anda...\n");

    int menu;
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        menuBuatMember();
        break;
    case 2:
        menuDaftarMember();
        break;
    default:
        break;
    }
}

int main()
{
    loadDummyData();
    // printSemuaBukuTersedia();

    // printSyaratKetentuan();

    menuSelection();
}