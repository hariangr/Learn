#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char stringRegister[100];
int intRegister;

// Struct untuk Buku
struct BukuModel
{
    char id[3]; // Kenapa 3? :3
    char jenis[50];
    char judul[50];
};

// Tempat menyimpan daftar buku yang tersedia (Lihat function [loadDataBukuTersedia])
struct BukuModel bukuTersedia[5];

// Function untuk membantu menambahkan buku ke daftar [bukuTersedia]
void tambahBukuTersedia(int _index, char _id[3], char _jenis[50], char _judul[50])
{
    struct BukuModel _buku;
    strcpy(_buku.id, _id);
    strcpy(_buku.jenis, _jenis);
    strcpy(_buku.judul, _judul);

    bukuTersedia[_index] = _buku;
}

// Function untuk mengisi daftar [bukuTersedia]
void loadDataBukuTersedia()
{
    tambahBukuTersedia(0, "A1", "Pemrograman", "Trick for C++");
    tambahBukuTersedia(1, "A2", "Sastra Jepang", "Katakana & Kanji 2");
    tambahBukuTersedia(2, "A3", "Teknologi", "Cisco Networking");
    tambahBukuTersedia(3, "A4", "Matematika", "Statistika jilid 2");
    tambahBukuTersedia(4, "A5", "Sains & physics", "Anatomi Tubuh  Manusia");
}

// Function untuk mengclear screen, karena aku pake Mac dan kau pake Windows
void clearScreen()
{
    system("cls||clear");
}

// Function untuk mencari index buku di [bukuTersedia] jika yang diketahui hanya [id] bukunya saja
//
// Misal mencari index untuk buku dengan id A3
// getIndexByBookId("A3") akan me-return index 2
// Function ini akan me-return -1 jika id yang diminta ternyata tidak ditemukan
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

// Function untuk mencari apakah sebuah buku dengan id tertentu ada di daftar [bukuTersedia]
//
// Misal mengecek apakah buku dengan id A5 ada
// cekIdSudahAda("A5") akan me-return true karena ada di daftar buku (Lihat [loadDataBukuTersedia])
//
// Akan me-return false jika id yang dicari tidak ada
// cekIdSudahAda("C9") akan me-return false
bool cekIdSudahAda(char _id[3])
{
    // Function ini memakai function getIndexByBookId
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

// Menu 2
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

// Menu 1
void menuBuatMember()
{
    printf("========================================\n");
    printf("|       ***Membuat Member Baru***      |\n");
    printf("========================================\n");

    char nama_member[20];
    printf("Nama      : ");
    fflush(stdin);
    main(12, NULL);
    strcpy(nama_member, stringRegister);

    char alamat_member[20];
    printf("\nAlamat    : ");
    fflush(stdin);
    main(12, NULL);
    strcpy(alamat_member, stringRegister);

    char ttl_member[2][10][4];
    printf("\nTTL       : ");
    fflush(stdin);
    main(12, NULL);
    strcpy(ttl_member, stringRegister);

    char pekerjaan_member[20];
    printf("\nPekerjaan : ");
    fflush(stdin);
    main(12, NULL);
    strcpy(pekerjaan_member, stringRegister);

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

// Menu 3
void menuPinjamBuku()
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
    fflush(stdin);
    main(12, NULL);
    strcpy(nama_penyewa_buku, stringRegister);

    int jumlah_peminjaman;
    do
    {
        printf("Jumlah Jenis Buku yang Ingin Dipinjam [max 5]    : ");
        main(11, NULL);
        jumlah_peminjaman = intRegister;

        if ((jumlah_peminjaman > 5) || (jumlah_peminjaman < 1))
        {
            printf("Jumlah jenis buku maximal 5. Silahkan ulangi kembali\n");
        }
    } while ((jumlah_peminjaman > 5) || (jumlah_peminjaman < 1));

    char kode[5][3];
    int jumlah[5]; // Menyimpan jumlah buku per judul buku yang dipinjam
    if ((jumlah_peminjaman <= 5) && (jumlah_peminjaman >= 1))
    {
        int i = 0;
        while (i < jumlah_peminjaman)
        {
            printf("\n=======================================\n");
            printf("| buku ke-%d \n", i + 1);
            printf("| Kode Buku                 : ");
            main(12, NULL);
            strcpy(kode[i], stringRegister);

            if (cekIdSudahAda(kode[i]) == true)
            {
                printf("| Jumlah Buku yang Dipinjam : ");
                main(11, NULL);
                jumlah[i] = intRegister;
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

    int tanggal_pinjam;
    while (1)
    {
        printf("Tanggal [DD]   : ");
        main(11, NULL);
        tanggal_pinjam = intRegister;

        if (tanggal_pinjam < 1 || tanggal_pinjam > 31)
        {
            printf("masukan ulang data..\n");
        }
        else
        {
            break;
        }
    }

    int bulan_pinjam;
    while (1)
    {
        printf("Bulan [MM]     : ");
        main(11, NULL);
        bulan_pinjam = intRegister;

        if (bulan_pinjam < 1 || bulan_pinjam > 12)
        {
            printf("masukan ulang data..\n");
        }
        else
        {
            break;
        }
    }

    int tahun_pinjam;
    while (1)
    {
        printf("Tahun [YYYY]   : ");
        main(11, NULL);
        tahun_pinjam = intRegister;

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

    if (jumlah_peminjaman > 0)
    {
        int i = 0;
        while (i < jumlah_peminjaman)
        {
            int index = getIndexByBookId(kode[i]);
            struct BukuModel _buku;
            _buku = bukuTersedia[index];
            printf(" %s         %s           %s             %d  \n\n", kode[i], _buku.jenis, _buku.judul, jumlah[i]);
            i++;
        }
    }
    printf("\n\n\n\t\t*****Terima Kasih  %s Atas Kunjungan Anda!***** \n", nama_penyewa_buku);
}

// Menu 4 (Belum selesai)
/*
void menuCekDenda()
{
    //input tanggal kembali
    printf("\nTanggal Kembali\n");

    int tanggal_kembali;
    while (1)
    {
        printf("Tanggal [DD]   : ");
        fflush(stdin);
        tanggalKembali = getsInt();
        if (tanggal_kembali < 1 || tanggal_kembali > 31)
        {
            printf("masukan ulang data..\n");
        }
        else
        {
            break;
        }
    }

    int bulan_kembali;
    while (1)
    {
        printf("Bulan [MM]     : ");
        bulan_kembali = getsInt();
        if (bulan_kembali < 1 || bulan_kembali > 12)
        {
            printf("masukan ulang data..\n");
        }
        else
        {
            break;
        }
    }

    int tahun_kembali;
    while (1)
    {
        printf("Tahun [YYYY]   : ");
        tahun_kembali = getsInt();
        if (tahun_kembali < 2018)
        {
            printf("masukan ulang data..\n");
        }
        else
        {
            break;
        }
    }

    clearScreen();

    system("color 0");

    int lama_peminjaman = (tanggal_kembali - tanggal_pinjam) + ((bulan_kembali - bulan_pinjam) * 30) + ((tahun_kembali - tahun_pinjam) * 360);
    int terlambat = lama_peminjaman - 7;

    int denda = 0;
    if (lama_peminjaman > 7)
    {
        denda = terlambat * 1000;
    }
    else if (terlambat <= 7)
    {
        terlambat = 0;
    }

    int tanggal_jt;
    int bulan_jt;
    int tahun_jt;
    tanggal_jt = tanggal_pinjam + 7;
    bulan_jt = bulan_pinjam + (tanggal_jt / 30);
    tahun_jt = tahun_pinjam + (bulan_jt / 12);
    if (tanggal_jt > 30)
    {
        tanggal_jt -= 30;
    }
    if (bulan_jt > 12)
    {
        bulan_jt -= 12;
    }

    printf("\n Tanggal Pinjam       : %d - %d - %d", tanggal_pinjam, bulan_pinjam, tahun_pinjam);
    printf("\n Tanggal Kembali      : %d - %d - %d", tanggal_kembali, bulan_kembali, tahun_kembali);
    printf("\n Tanggal Jatuh tempo  : %d - %d - %d", tanggal_jt, bulan_jt, tahun_jt);
    printf("\n Lama Peminjaman      : %d hari", lama_peminjaman);
    printf("\n Lama Keterlambatan   : %d hari", terlambat);
    printf("\n Denda                : Rp. %d", denda);
}
*/

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

    main(11, NULL);
    int menu = intRegister;

    switch (menu)
    {
    case 1:
        menuBuatMember();
        break;
    case 2:
        menuDaftarMember();
        break;
    case 3:
        menuPinjamBuku();
        break;
    case 4:
        printf("Belum selesai abang");
        break;
    case 5:
        exit(0);
    default:
        break;
    }
}

int main(int argc, char const *argv[])
{
    // Sebelum melakukan apapun dengan daftar buku, load dulu buku yang tersedia ke [bukuTersedia]
    if (argc < 3)
    {
        loadDataBukuTersedia();
        menuSelection();
    }

    // Input integer
    if (argc == 11)
    {
        intRegister = NULL;
        int temp;
        fflush(stdin);
        scanf("%d", &temp);
        intRegister = temp;
    }

    // Input string
    if (argc == 12)
    {
        memset(stringRegister, 0, sizeof(stringRegister));
        char temp[100];
        fflush(stdin);
        scanf("%[^\n]s", &temp);
        strcpy(stringRegister, temp);
    }

    return 0;
}
