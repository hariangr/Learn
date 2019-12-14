// String adalah kata...
// String adalah array dari huruf
// String adalah array dari char
// Misal char kata[100]

// Function strcpy itu ada di dalem string.h
#include <string.h>

// Function printf itu ada di dalem stdio.h
#include <stdio.h>

int main()
{

    // Cara memasukkan nilai string ke sebuah char array

    // Cara 1, cara memasukkan item ke array biasa (Ribet)
    char nama1[100] = { 'K',
                        'u',
                        's',
                        'u',
                        'm',
                        'a'
    };

    // %s untuk print string
    printf("%s\n", nama1);


    // Cara 2, pakai pointer (Ribet juga)
    // Perhatikan disini nama2 gak keliatan panjang arraynya
    // Why? susah dijelaskan
    char *nama2 = "Irianto bgst";
    printf("%s\n", nama2);


    // Cara 3, agak gampang
    char nama3[100];
    strcpy(nama3, "Ni Wayan Rage Seduk");
    printf("%s\n", nama3);
}

// Warning! untuk panjang variabelnya, lebihin lagi 1 untuk suatu masalah teknis yang terlalu susah untuk dijelaskan
// Misal mau masukan teks yang panjangnya 12 huruf ("Irianto bgst"), bikin array yang panjangnya setidaknya 13 huruf
// Why? Susah dijelasin :P

// Pake aja care yang ketiga, pls
// Susah jelasin yg 1 dan 2 :P