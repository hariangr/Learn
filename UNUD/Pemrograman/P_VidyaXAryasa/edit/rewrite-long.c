#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bukumodel.h"
#include "datasets.h"

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

void printDaftarMenu()
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
}

int main()
{
    // Sebelum melakukan apapun dengan daftar buku, load dulu buku yang tersedia ke [bukuTersedia]
    loadDataBukuTersedia();

    printSyaratKetentuan();
    printDaftarMenu();


    int menu;
    scanf("%d", &menu);
    int tahun_kembali, bulan_kembali, tanggal_kembali;
    int tahun_pinjam, bulan_pinjam, tanggal_pinjam;

    char nama_member[20], alamat_member[20], pekerjaan_member[20];
    int tanggal_lahir_member, tahun_lahir_member;
    char bulan_lahir_member[20];

    // Buat member
    if (menu == 1)
    {
        printf("========================================\n");
        printf("|       ***Membuat Member Baru***      |\n");
        printf("========================================\n");

        printf("Nama      : ");
        fflush(stdin);
        scanf("%[^\n]s", &nama_member);

        printf("\nAlamat    : ");
        fflush(stdin);
        scanf("%[^\n]s", &alamat_member);

        printf("\nPekerjaan : ");
        fflush(stdin);
        scanf("%[^\n]s", &pekerjaan_member);

        printf("\nTanggal Lahir      : ");
        fflush(stdin);
        scanf("%d", &tanggal_lahir_member);

        printf("\nBulan Lahir      : ");
        fflush(stdin);
        scanf("%s", &bulan_lahir_member);

        printf("\nTahun Lahir      : ");
        fflush(stdin);
        scanf("%d", &tahun_lahir_member);


        FILE *datamember = fopen("data_member.txt", "a");
        fprintf(datamember, "%s#%s#%s#%d#%s#%d\n", nama_member, alamat_member, pekerjaan_member, tanggal_lahir_member, bulan_lahir_member, tahun_lahir_member);
        fclose(datamember);

        printf("\nSukses menambah data member.\n\n");

        printf("=============================================\n");
        printf("|==== * Kartu Member Perpustakaan * ====|\n");
        printf("=============================================");
        printf("\n|         Nama      : %s             ", nama_member);
        printf("\n|         Alamat    : %s             ", alamat_member);
        printf("\n|         TTL       : %d %s %d       ", tanggal_lahir_member, bulan_lahir_member, tahun_lahir_member);
        printf("\n|         Pekerjaan : %s             ", pekerjaan_member);
        printf("\n=============================================\n");
        printf("|* Terima kasih %s Telah Bergabung *|\n", nama_member);
        printf("=============================================\n");
    }

    // Lihat daftar member
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
                char nama_member[20];
                char alamat_member[20];
                char pekerjaan_member[20];
                char bulan_lahir_member[20];
                int  tanggal_lahir_member;
                int tahun_lahir_member;

                fscanf(in, "%[^#]#%[^#]#%[^#]#%d#%[^#]#%d\n", &nama_member, &alamat_member, &pekerjaan_member, &tanggal_lahir_member, &bulan_lahir_member, &tahun_lahir_member);
                fflush(stdin);

                printf("%d. Nama      : %s", i + 1, nama_member);
                printf("\n   Alamat    : %s", alamat_member);
                printf("\n   Pekerjaan : %s", pekerjaan_member);
                printf("\n   TTL       : %d %s %d\n\n", tanggal_lahir_member, bulan_lahir_member, tahun_lahir_member);

                i++;
            }

            fclose(in);
            printf("Jumlah Member : %d\n", i);
        }
    }

    // Pinjam buku
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

        for (int i = 0; i < 5; i++)
        {
            struct BukuModel _buku = bukuTersedia[i];
            printf("|\t%s\t|\t%s\t|\t%s\t|\n", _buku.id, _buku.jenis, _buku.judul);
        }

        printf("---------------------------------------------------------------\n\n");

        char nama_penyewa_buku[20];
        printf("Nama Penyewa Buku    : ");
        fflush(stdin);
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
                scanf("%s", &kode[i]);

                if (cekIdSudahAda(kode[i]) == true)
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
        int k;
        char special[3];
        int random1;
        int random2;
        strcpy(special, "PNJ");
        for(k=0;k<2;k++){
            random1 = rand() % 888 + 111;
            random2 = rand() % 88888 + 11111;
        }


        FILE *datapinjam = fopen("data_peminjaman.txt", "a");
        fprintf(datapinjam, "%s%d%d#%s#%d#%d#%d#0#0#0#0\n", special, random1, random2, nama_penyewa_buku, tanggal_pinjam, bulan_pinjam, tahun_pinjam);
        fclose(datapinjam);


        printf("\nSukses menambah data peminjaman.\n\n");
        // getch();
        system("cls");

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

    // Hitung denda
    if (menu == 4){
        char kode[11];

        printf("Kode Peminjaman   : ");
        scanf("%s", &kode);

        char kode_data[11];
		char nama_data[20];
		int tgl_data;
		int bln_data;
		int tahun_data;
		int pm_tgl_data;
		int pm_bln_data;
		int pm_tahun_data;
		int total_data;
		int jumlah_data = 0;

        FILE *cek_data = fopen("data_peminjaman.txt", "r");
        while(!feof(cek_data)){
		    fscanf(cek_data,"%[^#]#%[^#]#%d#%d#%d#%d#%d#%d#%d\n", &kode_data, &nama_data, &tgl_data, &bln_data, &tahun_data, &pm_tgl_data, &pm_bln_data, &pm_tahun_data, &total_data);
		    jumlah_data++;
		}
		fclose(cek_data);

		char kode_data_tmp[jumlah_data][11];
		char nama_data_tmp[jumlah_data][20];
		int tgl_data_tmp[jumlah_data];
		int bln_data_tmp[jumlah_data];
		int tahun_data_tmp[jumlah_data];
		int pm_tgl_data_tmp[jumlah_data];
		int pm_bln_data_tmp[jumlah_data];
		int pm_tahun_data_tmp[jumlah_data];
		int total_data_tmp[jumlah_data];

		int ulang_data;

        FILE *ambil_data = fopen("data_peminjaman.txt", "r");
		for(ulang_data = 0; ulang_data < jumlah_data; ulang_data++){
            fscanf(ambil_data,"%[^#]#%[^#]#%d#%d#%d#%d#%d#%d#%d\n", &kode_data_tmp[ulang_data], &nama_data_tmp[ulang_data], &tgl_data_tmp[ulang_data], &bln_data_tmp[ulang_data], &tahun_data_tmp[ulang_data], &pm_tgl_data_tmp[ulang_data], &pm_bln_data_tmp[ulang_data], &pm_tahun_data_tmp[ulang_data], &total_data_tmp[ulang_data]);
		}

		int data_ambil;
		char hasil_data;
		printf("Jumlah Data : %d", jumlah_data);
		for(data_ambil = 0; data_ambil < jumlah_data; data_ambil++){
            if(strcmp(kode_data_tmp[data_ambil], kode) == 0){
                strcpy(hasil_data, "Yes");
                break;
            }else{
                strcpy(hasil_data, "No");
            }
		}

		printf("Data Pengembalian ? %s", hasil_data);

        printf("\nTanggal Pinjam\n");
        printf("\nTanggal [DD]   : ");
        printf("\nBulan [MM]     : ");
        printf("\nTahun [YYYY]   : ");

        printf("\nTanggal Kembali\n");
        printf("Tanggal [DD]   : ");
        scanf("%d", &tanggal_kembali);
        printf("Bulan [MM]     : ");
        scanf("%d", &bulan_kembali);
        printf("Tahun [YYYY]   : ");
        scanf("%d", &tahun_kembali);

        printf("Total pembayaran  : ");


    }

    // Exit
    if (menu == 5)
    {
        exit(0);
    }

    return 0;
}
