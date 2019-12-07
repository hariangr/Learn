#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 /*
main()
{
    int x; double y;
    char salam[]=   "\t\t\t selamat datang";

        printf("\n\n\n");
        for(x=0; salam[]!=NULL; x++)
        {
            printf("%c", salam[x]);
            for(y=0; y<=9999999; y++)
        {
        }
    } getch();
}      */
//fungsi untuk menampilkan list buku
char jenis[5][50] = {"Pemrograman", "Sastra Jepang", "Teknologi", "Matematika", "Sains & physics"},
     judul[5][50] = {"Trick for C++","Katakana & Kanji 2","Cisco Networking", "Statistika jilid 2","Anatomi Tubuh  Manusia"};
char id_buku[5][2] = {"A1", "A2", "A3", "A4", "A5"};

int getIndexByBookId(char id[2]){
    for (int i = 0; i < 5; i++){
        if (id[1] == id_buku[i][1]){

        return i;
        }
    }
 return -1;
}

bool cek(char id[2]){
    for (int i = 0; i < 5; i++){
        if (id[0] == id_buku[i][0] && id[1] == id_buku[i][1]){
            return true;
        }
    }
 return false;
}
int main (){

     int i=1, m=1, denda=0, terlambat=0;
     int tanggal_pinjam,bulan_pinjam, tahun_pinjam, jumlah_peminjaman;
     int menu,jumlah[5],tanggal_kembali, bulan_kembali, tahun_kembali;
     int tanggal_jt, bulan_jt, tahun_jt;
     char nama_member[20], alamat_member[20], ttl_member[2][10][4], kode[4][4], pekerjaan_member[20], nama_penyewa_buku[20];
     char ulang[5];
     char member[5];


    //tampilan menu
    do {
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
     printf ("=============Perpustakaan=============\n");
     printf ("| 1. Membuat Kartu Member Perpustakaan         |\n");
     printf ("| 2. Melihat Daftar Member                      |\n");
     printf ("| 3. Pinjam Buku                      |\n");
     printf ("| 4. Pengecekan Denda                 |\n");
     printf ("| 5. Exit                            |\n");
     printf ("======================================\n");
     printf ("\n");
     printf ("Silahkan masukan nomor menu pilihan anda...\n");
     scanf("%d",&menu);
     fflush(stdin);

     /*Membersihkan Layar*/
     system("cls");

     system("color f0");
     if(menu == 1){
        printf ("========================================\n");
        printf ("|       ***Membuat Member Baru***      |\n");
        printf ("========================================\n");
        printf ("Nama      : ");
        scanf ("%[^\n]s",&nama_member);
        fflush(stdin);
        printf ("\nAlamat    : ");
        scanf ("%[^\n]s",&alamat_member);
        fflush(stdin);
        printf ("\nTTL       : ");
        scanf ("%[^\n]s",&ttl_member);
        fflush(stdin);
        printf ("\nPekerjaan : ");
        scanf ("%[^\n]s",&pekerjaan_member);
        fflush(stdin);
        system("cls");

        FILE *datamember=fopen("data_member.txt","a");
			fprintf(datamember,"%s#%s#%s#%s#%d\n",nama_member, alamat_member, ttl_member, pekerjaan_member, m);
			fclose(datamember);
			printf("Sukses menambah data member.");
			getchar();
			system("cls");

        printf ("=============================================\n");
        printf ("|==== * Kartu Member Perpustakaan * ====|\n");
        printf ("=============================================");
        printf ("\n|         Nama      : %s             ", nama_member);
        printf ("\n|         Alamat    : %s             ", alamat_member);
        printf ("\n|         TTL       : %s             ", ttl_member);
        printf ("\n|         Pekerjaan : %s             ", pekerjaan_member);
        printf ("\n=============================================\n");
        printf ("|* Terima kasih %s Telah Bergabung *|\n", nama_member);
        printf ("=============================================\n");

     }system("color a");
     if(menu == 2){
        FILE *in=fopen("data_member.txt","r");
        if(!in){
            printf("tidak ada file");
        }else{
            int i = 0;
            while(!feof(in)){
                 fscanf(in,"%[^#]#%[^#]#%[^#]#%s\n", &nama_member, &alamat_member, &ttl_member, &pekerjaan_member);
                 fflush(stdin);
                 printf("%d.  Nama      : %s", i+1, nama_member);
                 printf("\n   Alamat    : %s", alamat_member);
                 printf("\n   TTL       : %s", ttl_member);
                 printf("\n   Pekerjaan : %s\n\n", pekerjaan_member);
                 i++;
            }fclose(in);
                printf("Jumlah Member : %d\n", i);
         }
     }
     if(menu == 3){
        printf("===============================================================\n");
        printf("=                                                             =\n");
        printf("=                  DAFTAR BUKU PERPUSTAKAAN                   =\n");
        printf("=                                                             =\n");
        printf("===============================================================\n\n");

        printf("---------------------------------------------------------------\n");
        printf("|   KODE BUKU   |     JENIS BUKU      |        JUDUL BUKU     |\n");
        printf("---------------------------------------------------------------\n");
        for (int l = 0; l < 5; l++){
            printf("|\t%s\t|\t%s\t|\t%s\t|\n", id_buku[l], jenis[l], judul[l]);
        }printf("---------------------------------------------------------------\n\n");

        printf("Nama Penyewa Buku    : ");
        scanf("%[^\n]s", &nama_penyewa_buku);

            do{
               printf("Jumlah Jenis Buku yang Ingin Dipinjam [max 5]    : ");
               scanf("%d", &jumlah_peminjaman);
                if((jumlah_peminjaman > 5) || (jumlah_peminjaman < 1)){
                    printf("Jumlah jenis buku maximal 5. Silahkan ulangi kembali\n");
                }
            } while((jumlah_peminjaman > 5) || (jumlah_peminjaman < 1));
            if((jumlah_peminjaman <= 5) && (jumlah_peminjaman >= 1)){
               while (i <= jumlah_peminjaman){
                    printf("\n=======================================\n");
                    printf("| buku ke-%d \n", i);
                    printf("| Kode Buku                 : ");
                    scanf("%s", &kode[i]);
                     if(cek(kode[i]) == true){
                        printf("| Jumlah Buku yang Dipinjam : ");
                        scanf("%d", &jumlah[i]);
                        printf("=======================================\n");
                        i++;
                     }else{
                        printf("Kode buku salah. Perhatikan penulisan dan silahkan ulangi kembali!");
                      }

                }
            }

        //input tanggal pinjam
        printf("\nTanggal Pinjam\n");
        while(1){
        printf("Tanggal [DD]   : ");
        scanf("%d", &tanggal_pinjam);
        if(tanggal_pinjam<1||tanggal_pinjam>31){
           printf("masukan ulang data..\n");
        }else{
            break;
         }
        }while(1){
         printf("Bulan [MM]     : ");
         scanf("%d", &bulan_pinjam);
         if(bulan_pinjam<1||bulan_pinjam>12){
            printf("masukan ulang data..\n");
         }else{
            break;
          }
         }while(1){
          printf("Tahun [YYYY]   : ");
          scanf("%d", &tahun_pinjam);
          if(tahun_pinjam<2018){
             printf("masukan ulang data..\n");
          }else{
            break;
           }
          }system("cls");

        system("color D");
        printf("\nNama Penyewa Buku    : %s", nama_penyewa_buku);
        printf("\nJumlah Buku          : %d\n\n", jumlah_peminjaman);

        printf("-----------------------------------------------------------------\n");
        printf("| KODE BUKU |   JENIS BUKU   |     JUDUL BUKU     |  JUMLAH BUKU|\n");
        printf("-----------------------------------------------------------------\n");


        int i=1;
        if (jumlah_peminjaman>0){
            while(i<=jumlah_peminjaman){
                int index = getIndexByBookId(kode[i]);
                    printf(" %s         %s           %s             %d  \n\n", kode[i], jenis[index], judul[index], jumlah[i]);
                    i++;
            }
        }
        printf("\n\n\n\t\t*****Terima Kasih  %s Atas Kunjungan Anda!***** \n",nama_penyewa_buku);
     }
    if(menu == 4){
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
       /* printf("\nApakah Anda Punya Member ? (y/n)");
        scanf("%s", &member);
     if(strcmp(member, "y") == 0){
        denda=terlambat*500;
    }*/
    //perhitungan jatuh tempo pengembalian
    tanggal_jt = tanggal_pinjam+7;
    bulan_jt = bulan_pinjam+(tanggal_jt/30);
    tahun_jt = tahun_pinjam+(bulan_jt/12);
    if(tanggal_jt>30){
        tanggal_jt-=30;
    }if(bulan_jt>12){
        bulan_jt-=12;
  }


    printf("\n Tanggal Pinjam       : %d - %d - %d", tanggal_pinjam, bulan_pinjam, tahun_pinjam);
    printf("\n Tanggal Kembali      : %d - %d - %d", tanggal_kembali, bulan_kembali, tahun_kembali);
    printf("\n Tanggal Jatuh tempo  : %d - %d - %d", tanggal_jt, bulan_jt, tahun_jt);
    printf("\n Lama Peminjaman      : %d hari", lama_peminjaman);
    printf("\n Lama Keterlambatan   : %d hari", terlambat);
    printf("\n Denda                : Rp. %d", denda);



    }if (menu == 5){
      getch();
    }
    //mengulang program
     printf("\n\n--------------------------------\n");
     printf(" Apakah ingin mengulang ? (y/n)");
     printf("\n--------------------------------\n");
		scanf("%s", &ulang);
		system("cls");
	}while(strcmp(ulang, "y") == 0);
    return 0;
}
