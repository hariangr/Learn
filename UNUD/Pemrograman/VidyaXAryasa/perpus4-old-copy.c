#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int i = 1, m = 1, denda = 0, terlambat = 0;
    int jt_tgl, jt_bln, jt_thn;
    int menu, jumlah, kmbltgl, kmblbln, kmblthn, pnjmtgl, pnjmbln, pnjmthn, jumlah_peminjaman;
    char nama_mmbr[20], alamat_mmbr[20], ttl_mmbr[2][10][4], pekerjaan_mmbr[20], kode[4][4], nama[20];
    char jenis[5][100] = {"Pemrograman", "Sastra Jepang", "Teknologi", "Matematika", "Sains & physics"},
         judul[5][100] = {"Trick for C++", "Katakana & Kanji 2", "Cisco Networking", "Statistika jilid 2", "Anatomi Tubuh  Manusia"};
    char ulang[10];
    char member[10];

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

        system("color f0");
        if (menu == 1)
        {
            printf("========================================\n");
            printf("|       ***Create a New Member***      |\n");
            printf("========================================\n");
            printf("Nama      : ");
            scanf("%[^\n]s", &nama_mmbr);
            fflush(stdin);
            printf("\nAlamat    : ");
            scanf("%[^\n]s", &alamat_mmbr);
            fflush(stdin);
            printf("\nTTL       : ");
            scanf("%[^\n]s", &ttl_mmbr);
            fflush(stdin);
            printf("\nPekerjaan : ");
            scanf("%[^\n]s", &pekerjaan_mmbr);
            fflush(stdin);
            system("cls");

            FILE *datamember = fopen("data_member.txt", "a");
            fprintf(datamember, "%s#%s#%s#%s#%d\n", nama_mmbr, alamat_mmbr, ttl_mmbr, pekerjaan_mmbr, m);
            fclose(datamember);
            printf("Sukses menambah data member.");
            getchar();
            system("cls");

            printf("=============================================\n");
            printf("|==== * Card Member Perpustakaan Kita * ====|\n");
            printf("=============================================");
            printf("\n|         Nama      : %s             ", nama_mmbr);
            printf("\n|         Alamat    : %s             ", alamat_mmbr);
            printf("\n|         TTL       : %s             ", ttl_mmbr);
            printf("\n|         Pekerjaan : %s             ", pekerjaan_mmbr);
            printf("\n=============================================\n");
            printf("|* Terimakasih %s Telah Bergabung *|\n", nama_mmbr);
            printf("=============================================\n");
        }
        system("color a");
        if (menu == 2)
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
        }

        if (menu == 3)
        {
            printf("===============================================================\n");
            printf("=                                                             =\n");
            printf("=                  DAFTAR BUKU PERPUSTAKAAN                   =\n");
            printf("=                                                             =\n");
            printf("===============================================================\n\n");

            printf("---------------------------------------------------------------\n");
            printf("|   KODE BUKU   |     JENIS BUKU      |        JUDUL BUKU     |\n");
            printf("---------------------------------------------------------------\n");
            printf("|     A1        |      Pemrograman    |     Trick for C       |\n");
            printf("|     A2        |     Sastra Jepang   |  Katakana & Kanji 2   |\n");
            printf("|     A3        |      Teknologi      |   Cisco Networking    |\n");
            printf("|     A4        |      Matematika     |  Statistika Jilid 2   |\n");
            printf("|     A5        |    Sains & physics  | Anatomi Tubuh Manusia |\n");
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
                    printf("  %s         %s       %s     %d   \n\n", kode[i], jenis[i], judul[i], jumlah);
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
        if (menu == 4)
        {
            //   getch();
        }
        //mengulang program
        printf("\n\n--------------------------------\n");
        printf(" Apakah ingin mengulang ? (y/n)");
        printf("\n--------------------------------\n");
        scanf("%s", &ulang);
        system("cls");
    } while (strcmp(ulang, "y") == 0);
    return 0;
}
