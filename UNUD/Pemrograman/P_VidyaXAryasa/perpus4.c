#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char id_buku[5][2] = {"A1", "A2", "A3", "A4", "A5"};
char jenis[5][100] = {"Pemrograman", "Sastra Jepang", "Teknologi", "Matematika", "Sains & physics"};
char judul[5][100] = {"Trick for C++", "Katakana & Kanji 2", "Cisco Networking", "Statistika jilid 2", "Anatomi Tubuh  Manusia"};

void menuOneLibraryCard()
{
    int m = 1; // << wtf is this for

    printf("========================================\n");
    printf("|       ***Create a New Member***      |\n");
    printf("========================================\n");

    char nama_mmbr[20];
    printf("Nama      : ");
    scanf("%[^\n]s", &nama_mmbr);

    char alamat_mmbr[20];
    printf("\nAlamat    : ");
    scanf("%[^\n]s", &alamat_mmbr);
    fflush(stdin);

    char ttl_mmbr[2][10][4];
    printf("\nTTL       : ");
    scanf("%[^\n]s", &ttl_mmbr);
    fflush(stdin);

    char pekerjaan_mmbr[20];
    printf("\nPekerjaan : ");
    scanf("%[^\n]s", &pekerjaan_mmbr);
    fflush(stdin);

    system("cls");

    FILE *datamember = fopen("data_member.txt", "a");
    fprintf(datamember, "%s#%s#%s#%s#%d\n", nama_mmbr, alamat_mmbr, ttl_mmbr, pekerjaan_mmbr, m);
    fclose(datamember);

    printf("Sukses menambah data member.");

    printf("=============================================\n");
    printf("|==== * Card Member Perpustakaan Kita * ====|\n");
    printf("=============================================\n");
    printf("|         Nama      : %s\n", nama_mmbr);
    printf("|         Alamat    : %s\n", alamat_mmbr);
    printf("|         TTL       : %s\n", ttl_mmbr);
    printf("|         Pekerjaan : %s\n", pekerjaan_mmbr);
    printf("=============================================\n");
    printf("|* Terimakasih %s Telah Bergabung *|\n", nama_mmbr);
    printf("=============================================\n");
}

void menuTwoCheckMember()
{
    char nama_mmbr[20];
    int alamat_mmbr[20];
    int ttl_mmbr[2][10][4];
    int pekerjaan_mmbr[20];

    FILE *in = fopen("data_member.txt", "r");
    if (!in)
    {
        printf("tidak ada file");
        return;
    }

    int i = 0;
    while (!feof(in))
    {
        fscanf(in, "%[^#]#%[^#]#%[^#]#%s\n", &nama_mmbr, &alamat_mmbr, &ttl_mmbr, &pekerjaan_mmbr);
        fflush(stdin);
        printf("%d.  Nama      : %s", i + 1, nama_mmbr);
        printf("\n    Alamat    : %s", alamat_mmbr);
        printf("\n    TTL       : %s", ttl_mmbr);
        printf("\n    Pekerjaan : %s\n\n", pekerjaan_mmbr);
        i++;
    }
    fclose(in);
    printf("JUMLAH MEMBER : %d\n", i);
}

void menuThreeBorrowBook()
{
    char member[10];
    char nama_mmbr[20], alamat_mmbr[20], ttl_mmbr[2][10][4], pekerjaan_mmbr[20], kode[4][4], nama[20];
    int jumlah, kmbltgl, kmblbln, kmblthn, pnjmtgl, pnjmbln, pnjmthn, jumlah_peminjaman;
    int jt_tgl, jt_bln, jt_thn;
    int i = 1;
    int denda = 0;
    int terlambat = 0;
    printf("===============================================================\n");
    printf("=                                                             =\n");
    printf("=                  DAFTAR BUKU PERPUSTAKAAN                   =\n");
    printf("=                                                             =\n");
    printf("===============================================================\n\n");

    printf("---------------------------------------------------------------\n");
    printf("|   KODE BUKU   |     JENIS BUKU      |        JUDUL BUKU     |\n");
    printf("---------------------------------------------------------------\n");
    for (int l = 0; l < 5; l++)
    {
        printf("|\t%s\t|\t%s\t|\t%s\t|\n", id_buku[l], jenis[l], judul[l]);
    }
    printf("---------------------------------------------------------------\n\n");

    printf("Nama Penyewa Buku    : ");
    scanf("%[^\n]s", &nama);
    do
    {
        printf("Jumlah Peminjaman    : ");
        scanf("%d", &jumlah_peminjaman);
        if ((jumlah_peminjaman > 5) || (jumlah_peminjaman < 1))
        {
            printf("Jumlah Peminjaman Maximal 5\n");
        }
    } while ((jumlah_peminjaman > 5) || (jumlah_peminjaman < 1));

    if ((jumlah_peminjaman <= 5) && (jumlah_peminjaman >= 1))
    {
        while (i <= jumlah_peminjaman)
        {
            printf("\n=======================================\n");
            printf("| buku ke-%d \n", i);
            printf("| Kode Buku                 : ");
            scanf("%s", &kode[i]);
            printf("| Jumlah Buku Yang Dipinjam : ");
            scanf("%d", &jumlah);
            printf("=======================================\n");
            i++;
        }
    }

    //input tanggal pinjam
    printf("\nTanggal Pinjam\n");
    while (1)
    {
        printf("Tanggal [DD]   : ");
        scanf("%d", &pnjmtgl);
        if (pnjmtgl < 1 || pnjmtgl > 31)
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
        scanf("%d", &pnjmbln);
        if (pnjmbln < 1 || pnjmbln > 12)
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
        scanf("%d", &pnjmthn);
        if (pnjmthn < 1)
        {
            printf("masukan ulang data..\n");
        }
        else
        {
            break;
        }
    }

    //input tanggal kembali
    printf("\nTanggal Kembali\n");
    while (1)
    {
        printf("Tanggal [DD]   : ");
        scanf("%d", &kmbltgl);
        if (kmbltgl < 1 || kmbltgl > 31)
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
        scanf("%d", &kmblbln);
        if (kmblbln < 1 || kmblbln > 12)
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
        scanf("%d", &kmblthn);
        if (kmblthn < 1)
        {
            printf("masukan ulang data..\n");
        }
        else
        {
            break;
        }
    }

    system("cls");
    system("color 0");

    //proses perhitungan denda
    int lamaPinjam = (kmbltgl - pnjmtgl) + ((kmblbln - pnjmbln) * 30) + ((kmblthn - pnjmthn) * 360);
    int terlambat = lamaPinjam - 7;

    if (lamaPinjam > 7)
    {
        denda = terlambat * 1000;
    }
    else if (terlambat <= 7)
    {
        terlambat = 0;
    }

    printf("\nApakah Anda Punya Member ? (y/n)");
    scanf("%s", &member);
    if (strcmp(member, "y") == 0)
    {
        denda = terlambat * 500;
    }

    //perhitungan jatuh tempo pengembalian
    jt_tgl = pnjmtgl + 7;
    jt_bln = pnjmbln + (jt_tgl / 30);
    jt_thn = pnjmthn + (jt_bln / 12);
    if (jt_tgl > 30)
    {
        jt_tgl -= 30;
    }
    if (jt_bln > 12)
    {
        jt_bln -= 12;
    }
    system("color D");

    printf("\nNama Penyewa Buku    : %s", nama);
    printf("\nJumlah Buku          : %d\n\n", jumlah_peminjaman);

    printf("-----------------------------------------------------------------\n");
    printf("| KODE BUKU |   JENIS BUKU   |     JUDUL BUKU     |  JUMLAH BUKU|\n");
    printf("-----------------------------------------------------------------\n");

    int i = 1;
    if (jumlah_peminjaman > 0)
    {
        while (i <= jumlah_peminjaman)
        {
            printf("  %s         %s       %s     %d   \n\n", kode[i], jenis, judul, jumlah);
            i++;
        }
    }

    printf("\n Tanggal Pinjam       : %d - %d - %d", pnjmtgl, pnjmbln, pnjmthn);
    printf("\n Tanggal Kembali      : %d - %d - %d", kmbltgl, kmblbln, kmblthn);
    printf("\n Tanggal Jatuh tempo  : %d - %d - %d", jt_tgl, jt_bln, jt_thn);
    printf("\n Lama Peminjaman      : %d hari", lamaPinjam);
    printf("\n Lama Keterlambatan   : %d hari", terlambat);
    printf("\n Denda                : Rp. %d", denda);

    printf("\n\n\n\t\t*****TERIMAKASIH  %s ATAS KUNJUNGAN ANDA!***** \n", nama);
}

int main()
{
    char ulang[10];

    int menu;

    //tampilan menu
    do
    {
        system("color 7D");
        printf("----------------------------------------------------------------\n");
        printf("|                Syarat Dan Ketentuan:                         |");
        printf("\n----------------------------------------------------------------\n");
        printf("| 1. Diharap Mengisi Data Peminjaman Buku                      |\n");
        printf("| 2. Apabila Terlambat Mengembalikan Buku Akan Dikenakan Denda |\n");
        printf("----------------------------------------------------------------\n");
        printf("\n======================================\n");
        printf("|       Selamat Datang Di Menu       |\n");
        printf("======================================\n");
        printf("=============Perpustakaan=============\n");
        printf("| 1. Buat Kartu Perpustakaan         |\n");
        printf("| 2. cek member                      |\n");
        printf("| 3. Pinjam Buku                     |\n");
        printf("| 4. Exit                            |\n");
        printf("======================================\n");
        printf("\n");
        printf("Silahkan masukkan nomor pada menu...\n");
        scanf("%d", &menu);
        fflush(stdin);

        /*Membersihkan Layar*/
        system("cls");
        system("clear");

        if (menu == 1)
        {
            menuOneLibraryCard();
        }
        if (menu == 2)
        {
            menuTwoCheckMember();
        }

        if (menu == 3)
        {
            menuThreeBorrowBook();
        }

        if (menu == 4)
        {
            // getch();
            // exit(0);
        }

        //mengulang program
        printf("\n\n--------------------------------\n");
        printf(" Apakah ingin mengulang ? (y/n)");
        printf("\n--------------------------------\n");
        scanf("%s", ulang);
        system("cls");
    } while (strcmp(ulang, "y") == 0);

    return 0;
}
