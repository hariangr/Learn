#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct untuk Buku
struct BukuModel{
    char id[3];
    char jenis[50];
    char judul[50];
};

// Tempat menyimpan daftar buku yang tersedia (Lihat function [loadDataBukuTersedia])
struct BukuModel bukuTersedia[5];

// Function untuk membantu menambahkan buku ke daftar [bukuTersedia]
void tambahBukuTersedia(int index, char id[3], char jenis[50], char judul[50]){
    struct BukuModel buku;
    strcpy(buku.id, id);
    strcpy(buku.jenis, jenis);
    strcpy(buku.judul, judul);

    bukuTersedia[index] = buku;
}

// Function untuk mengisi daftar [bukuTersedia]
void loadDataBukuTersedia(){
    tambahBukuTersedia(0, "A1", "Pemrograman", "Trick for C++");
    tambahBukuTersedia(1, "A2", "Sastra Jepang", "Katakana & Kanji 2");
    tambahBukuTersedia(2, "A3", "Teknologi", "Cisco Networking");
    tambahBukuTersedia(3, "A4", "Matematika", "Statistika jilid 2");
    tambahBukuTersedia(4, "A5", "Sains & physics", "Anatomi Tubuh  Manusia");
}

// Function untuk mengclear screen, karena aku pake Mac dan kau pake Windows

// Function untuk mencari index buku di [bukuTersedia] jika yang diketahui hanya [id] bukunya saja
//
// Misal mencari index untuk buku dengan id A3
// getIndexByBookId("A3") akan me-return index 2
// Function ini akan me-return -1 jika id yang diminta ternyata tidak ditemukan

int getIndexByBookId(char _id[3]){
    for (int i = 0; i < 5; i++){
        if (strcmp(_id, bukuTersedia[i].id) == 0){
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
bool cekIdSudahAda(char id[3]){
    // Function ini memakai function getIndexByBookId
    int index = getIndexByBookId(id);

    if (index == -1){
        return false;
    }else{
        return true;
    }
}

void printSemuaBukuTersedia(){
    printf("INDEX\tKODE\tJENIS\tJUDUL\n");

    for (int i = 0; i < 5; i++){
        struct BukuModel buku = bukuTersedia[i];
        printf("%d \t%s \t%s \t%s \n", i, buku.id, buku.jenis, buku.judul);
    }
}

void printSyaratKetentuan(){
    printf("----------------------------------------------------------------\n");
    printf("|                Syarat Dan Ketentuan:                         |\n");
    printf("----------------------------------------------------------------\n");
    printf("| 1. Diharap Mengisi Data Peminjaman Buku                      |\n");
    printf("| 2. Apabila Terlambat Mengembalikan Buku Akan Dikenakan Denda |\n");
    printf("----------------------------------------------------------------\n");
}

void printDaftarMenu(){
    printf("\n======================================\n");
    printf("|       Selamat Datang Di Menu       |\n");
    printf("======================================\n");
    printf("=============Perpustakaan=============\n");
    printf("| 1. Membuat Kartu Member Perpustakaan |\n");
    printf("| 2. Melihat Daftar Member             |\n");
    printf("| 3. Pinjam Buku                       |\n");
    printf("| 4. Exit                              |\n");
    printf("======================================\n");
    printf("\nSilahkan masukan nomor menu pilihan anda...\n");
}

int main(){
    // Sebelum melakukan apapun dengan daftar buku, load dulu buku yang tersedia ke [bukuTersedia]
    int menu;
    int denda=0;
    int tanggal_jt, bulan_jt, tahun_jt;
    int tahun_kembali, bulan_kembali, tanggal_kembali;
    int tahun_pinjam, bulan_pinjam, tanggal_pinjam;

    char nama_penyewa_buku[20];
    char member[2];
    char ulang[2];
    char nama_member[20], alamat_member[20], pekerjaan_member[20];
    int tanggal_lahir_member, tahun_lahir_member;
    char bulan_lahir_member[20];

    // Buat member
    do {
        system("color a");
        loadDataBukuTersedia();

        printSyaratKetentuan();
        printDaftarMenu();
        scanf("%d", &menu);
        system("cls");
        system("color 9");
    if (menu == 1){
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


        FILE *simpandatamember = fopen("data_member.txt", "a");
        fprintf(simpandatamember, "%s#%s#%s#%d#%s#%d\n", nama_member, alamat_member, pekerjaan_member, tanggal_lahir_member, bulan_lahir_member, tahun_lahir_member);
        fclose(simpandatamember);

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
    system("color d");
    if (menu == 2){

        printf("========================================\n");
        printf("|       ***Daftar Anggota Member***    |\n");
        printf("========================================\n\n");

        FILE *panggildata = fopen("data_member.txt", "r");
        if (!panggildata){
            printf("tidak ada file");
        }else{
            int i = 0;
            while (!feof(panggildata)){
                fscanf(panggildata, "%[^#]#%[^#]#%[^#]#%d#%[^#]#%d\n", &nama_member, &alamat_member, &pekerjaan_member, &tanggal_lahir_member, &bulan_lahir_member, &tahun_lahir_member);
                fflush(stdin);
                printf("%d. Nama      : %s", i + 1, nama_member);
                printf("\n   Alamat    : %s", alamat_member);
                printf("\n   Pekerjaan : %s", pekerjaan_member);
                printf("\n   TTL       : %d %s %d\n\n", tanggal_lahir_member, bulan_lahir_member, tahun_lahir_member);

                i++;
        }fclose(panggildata);
         printf("Jumlah Member : %d\n", i);
        }
    }

    // Pinjam buku
     system("color 5");
    if (menu == 3){
        printf("===============================================================\n");
        printf("=                                                             =\n");
        printf("=                  DAFTAR BUKU PERPUSTAKAAN                   =\n");
        printf("=                                                             =\n");
        printf("===============================================================\n\n");
        printf("---------------------------------------------------------------\n");
        printf("|   KODE BUKU   |     JENIS BUKU      |        JUDUL BUKU     |\n");
        printf("---------------------------------------------------------------\n");

        for (int i = 0; i < 5; i++){
            struct BukuModel buku = bukuTersedia[i];
            printf("|\t%s\t|\t%s\t|\t%s\t|\n", buku.id, buku.jenis, buku.judul);
        }

        printf("---------------------------------------------------------------\n\n");


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
        //input tanggal kembali
        printf("\nTanggal Kembali\n");
        while(1){
        printf("Tanggal [DD]   : ");
        scanf("%d", &tanggal_kembali);
        if(tanggal_kembali<1||tanggal_kembali>31){
            printf("masukan ulang data..\n");
        }else{
            break;
         }
        }while(1){
         printf("Bulan [MM]     : ");
         scanf("%d", &bulan_kembali);
         if(bulan_kembali<1||bulan_kembali>12){
            printf("masukan ulang data..\n");
         }else{
            break;
          }
         }while(1){
          printf("Tahun [YYYY]   : ");
          scanf("%d", &tahun_kembali);
          if(tahun_kembali<2018){
          printf("masukan ulang data..\n");
          }else{
            break;
           }

          }system("cls");

        system("color 0");

    //proses perhitungan denda
    int lama_peminjaman=(tanggal_kembali-tanggal_pinjam)+((bulan_kembali-bulan_pinjam)*30)+((tahun_kembali-tahun_pinjam)*360);
    int terlambat=lama_peminjaman-7;

    if (lama_peminjaman>7){
        denda=terlambat*1000;
    }else if(terlambat<=7){
        terlambat=0;
     }
      printf("\nApakah Anda Punya Member ? (y/n)");
        scanf("%s", &member);
     if(strcmp(member, "y") == 0){
        denda=terlambat*500;
    }
    //perhitungan jatuh tempo pengembalian
    tanggal_jt = tanggal_pinjam+7;
    bulan_jt = bulan_pinjam+(tanggal_jt/30);
    tahun_jt = tahun_pinjam+(bulan_jt/12);
    if(tanggal_jt>30){
        tanggal_jt-=30;
    }if(bulan_jt>12){
        bulan_jt-=12;
  }
        getch();
        system("cls");

        system("color D");
        printf("\nNama Penyewa Buku    : %s", nama_penyewa_buku);
        printf("\nJumlah Buku          : %d\n\n", jumlah_peminjaman);

        printf("-----------------------------------------------------------------\n");
        printf("| KODE BUKU |   JENIS BUKU   |     JUDUL BUKU     |  JUMLAH BUKU|\n");
        printf("-----------------------------------------------------------------\n");

        if (jumlah_peminjaman > 0){
            int i = 0;
            while (i < jumlah_peminjaman){
                int index = getIndexByBookId(kode[i]);
                struct BukuModel _buku;
                _buku = bukuTersedia[index];
                printf(" %s         %s           %s           %d  \n\n", kode[i], _buku.jenis, _buku.judul, jumlah[i]);
                i++;
        }
    }
        printf("\n Tanggal Pinjam       : %d - %d - %d", tanggal_pinjam, bulan_pinjam, tahun_pinjam);
        printf("\n Tanggal Kembali      : %d - %d - %d", tanggal_kembali, bulan_kembali, tahun_kembali);
        printf("\n Tanggal Jatuh tempo  : %d - %d - %d", tanggal_jt, bulan_jt, tahun_jt);
        printf("\n Lama Peminjaman      : %d hari", lama_peminjaman);
        printf("\n Lama Keterlambatan   : %d hari", terlambat);
        printf("\n Denda                : Rp. %d", denda);

        printf("\n\n\n\t\t*****Terima Kasih  %s Atas Kunjungan Anda!***** \n", nama_penyewa_buku);
    }
    // Exit
    if (menu == 5){
        exit(0);
    }

    //mengulang program
     printf("\n\n--------------------------------\n");
     printf(" Apakah ingin mengulang program ? (y/n)");
     printf("\n--------------------------------\n");
     scanf("%s", &ulang);
     system("cls");
	}while(strcmp(ulang, "y") == 0);
    return 0;
}
