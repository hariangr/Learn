#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

int hitung_harga_tiket(int hari, int jml_tiket)
{
    int tarif;
    int total_harga;

    if (hari == 1 || hari == 2 || hari == 3 || hari == 4 || hari == 5)
    {
        tarif = 50000;
    }
    else if (hari == 6 || hari == 7)
    {
        tarif = 60000;
    }

    total_harga = tarif * jml_tiket;

    return total_harga;
}

int main()
{
    int menu;
    // Membuat sebuah variabel bernama 'data' dengan tipe data 'struct Konsumen'
    struct Konsumen data;
    int kode_judul;
    int hari;
    int kode_snack;
    char tambah;
    int pilih;

    printf("-----------------------------------------------------------------------------\n");
    printf("                            PEMESANAN TIKET BIOSKOP                          \n");
    printf("                                   CINEMA XIX                                \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("MENU:\n");
    printf(" \t[1] Pesan Tiket\n");
    printf(" \t[2] Lihat Data Konsumen\n");
    printf(" \t[3] Keluar\n");
    printf("Masukkan pilihan Anda   : ");
    scanf("%d", &menu);
    fflush(stdin);
    system("cls");

    if (menu == 1)
    {
        printf("NOW SHOWING:\n");
        printf(" \t[1] Frozen II                    || 12.00 | 13.50\n");
        printf(" \t[2] Charlie's Angels             || 15.00 | 16.50\n");
        printf(" \t[3] Rumah Kentang: The Beginning || 19.30 \n");
        printf(" \t[4] Midway                       || 22.00\n");

        printf("Masukkan nama           : ");
        scanf("%[^\n]s", &data.nama);
        printf("Pilih judul film        : ");
        scanf("%d", &kode_judul);
        printf("Pilih jam               : ");
        scanf("%f", &data.jam_tayang);
        printf("Jumlah tiket yang dibeli: ");
        scanf("%d", &data.jumlah_tiket);

        if (kode_judul == 1)
        {
            strcpy(data.judul_film, "Frozen II");
        }
        else if (kode_judul == 2)
        {
            strcpy(data.judul_film, "Charlie's Angels");
        }
        else if (kode_judul == 3)
        {
            strcpy(data.judul_film, "Rumah Kentang: The Beginning");
        }
        else if (kode_judul == 4)
        {
            strcpy(data.judul_film, "Midway");
        }
        else
        {
            printf("Kode film yang Anda masukkan salah!");
            return 0;
        }
        system("cls");

        printf("Pilihan hari:\n");
        printf(" \t[1] Senin\n");
        printf(" \t[2] Selasa\n");
        printf(" \t[3] Rabu\n");
        printf(" \t[4] Kamis\n");
        printf(" \t[5] Jumat\n");
        printf(" \t[6] Sabtu\n");
        printf(" \t[7] Minggu\n");
        printf("Pilih hari              : ");
        scanf("%d", &hari);

        if (hari == 1 || hari == 2 || hari == 3 || hari == 4 || hari == 4 || hari == 5 || hari == 6 || hari == 7)
        {
            data.total_harga_tiket = hitung_harga_tiket(hari, data.jumlah_tiket);
        }
        else
        {
            printf("Kode hari yang Anda masukkan salah!");
            data.total_harga_tiket = 0;
            return 0;
        }

        printf("\nAda tambahan (y/t))? ");
        scanf("%s", &tambah);
        system("cls");

        if (tambah == 'y' || tambah == 'Y')
        {
            printf("Pilih paket snack dan minuman berikut:\n");

            char data_nama_snack_temp[50];
            int data_harga_snack_temp;
            int jumlah_data = 0;

            FILE *tampil = fopen("snack.txt", "r");
            while (!feof(tampil))
            {
                fscanf(tampil, "%[^#]#%d\n", &data_nama_snack_temp, &data_harga_snack_temp);
                jumlah_data++;
            }
            fclose(tampil);

            char data_nama_snack[jumlah_data][50];
            int data_harga_snack[jumlah_data];
            int angka_array = 0;

            FILE *tampil2 = fopen("snack.txt", "r");
            while (!feof(tampil2))
            {
                fscanf(tampil, "%[^#]#%d\n", &data_nama_snack[angka_array], &data_harga_snack[angka_array]);
                printf(" \t[%d] %s\n", angka_array + 1, data_nama_snack[angka_array]);
                printf(" \t    Harga : %d\n", data_harga_snack[angka_array]);
                angka_array++;
            }
            fclose(tampil2);

            printf("Masukkan pilihan Anda: ");
            scanf("%d", &kode_snack);
            printf("Jumlah               : ");
            scanf("%d", &data.jumlah_snack);

            kode_snack = kode_snack - 1;

            data.total_harga_snack = data_harga_snack[kode_snack] * data.jumlah_snack;
        }
        else if (tambah == 't' || tambah == 'T')
        {
            data.jumlah_snack = 0;
            data.total_harga_snack = 0;
        }
        else
        {
            printf("Kode yang Anda masukkan salah!");
            data.total_harga_snack = 0;
            return 0;
        }

        data.grand_total = data.total_harga_tiket + data.total_harga_snack;
        system("cls");

        system("color B");
        printf("-----------------------------------------------------------------------------\n");
        printf("                               TOTAL TRANSAKSI                               \n");
        printf("-----------------------------------------------------------------------------\n");
        printf("Halo %s, berikut rincian belanja Anda: \n", data.nama);
        printf("Anda akan menonton %s pukul %.2f \n", data.judul_film, data.jam_tayang);
        printf("Jumlah tiket        = %d \n", data.jumlah_tiket);
        printf("Total harga tiket   = %d \n", data.total_harga_tiket);
        printf("Jumlah snack        = %d \n", data.jumlah_snack);
        printf("Total harga snack   = %d \n", data.total_harga_snack);
        printf("\nGrand Total         = %d \n", data.grand_total);
        printf("-----------------------------------------------------------------------------\n");
        printf("                                TERIMA KASIH                                 \n");
        printf("-----------------------------------------------------------------------------\n");

        FILE *insert = fopen("list.txt", "a");
        fprintf(insert, "%s#%s#%d\n", data.nama, data.judul_film, data.grand_total);
        fclose(insert);

        printf("Tekan 1 untuk kembali ke menu awal ");
        scanf("%d", &pilih);
        system("color 7");

        if (pilih == 1)
        {
            system("cls");
            main();
        }
        else
        {
            return 0;
        }
    }
    else if (menu == 2)
    {
        system("color A");
        printf("-----------------------------------------------------------------------------\n");
        printf("                            LIST PEMBELIAN TIKET                         	 \n");
        printf("                                CINEMA XIX                                	 \n");
        printf("-----------------------------------------------------------------------------\n");
        FILE *list_pembeli = fopen("list.txt", "r");
        if (!list_pembeli)
        {
            printf("Tidak Ada List");
        }
        else
        {
            int i = 1;
            while (!feof(list_pembeli))
            {
                fscanf(list_pembeli, "%[^#]#%[^#]#%d\n", &data.nama, &data.judul_film, &data.grand_total);
                printf("%d. Nama       : %s\n", i, data.nama);
                printf("   Judul Film : %s\n", data.judul_film);
                printf("   Total harga: %d\n", data.grand_total);
                i++;
            }
        }
        printf("Tekan 1 untuk kembali ke menu awal ");
        scanf("%d", &pilih);
        system("color 7");

        if (pilih == 1)
        {
            system("cls");
            main();
        }
        else
        {
            return 0;
        }
    }
    else if (menu == 3)
    {
        system("color 4");
        printf("Good Bye!");
        return 0;
    }
    else
    {
        printf("Kode menu yang Anda masukkan salah!");
        system("cls");
        main();
    }

    return 0;
}
