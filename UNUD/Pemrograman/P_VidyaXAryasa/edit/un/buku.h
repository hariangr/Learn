#include <string.h>

// Struct untuk Buku
struct BukuModel
{
    char id[3];
    char jenis[50];
    char judul[50];
};

// Tempat menyimpan daftar buku yang tersedia (Lihat function [loadDataBukuTersedia])
struct BukuModel bukuTersedia[5];

// Function untuk membantu menambahkan buku ke daftar [bukuTersedia]
void tambahBukuTersedia(int index, char id[3], char jenis[50], char judul[50])
{
    struct BukuModel buku;
    strcpy(buku.id, id);
    strcpy(buku.jenis, jenis);
    strcpy(buku.judul, judul);

    bukuTersedia[index] = buku;
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
bool cekIdSudahAda(char id[3])
{
    // Function ini memakai function getIndexByBookId
    int index = getIndexByBookId(id);

    if (index == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
