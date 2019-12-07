#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TOTAL_BUKU_TERSEDIA 5

struct BukuModel
{
    char id[2];
    char jenis[50];
    char judul[50];
};

struct BukuModel bukuTersedia[TOTAL_BUKU_TERSEDIA];

int getIndexByBookId(char _id[2])
{
    for (int i = 0; i < TOTAL_BUKU_TERSEDIA; i++)
    {
        if (strcmp(_id, bukuTersedia[i].id) == 1)
        {
            return i;
        }
    }

    return -1;
}

bool cekIdSudahAda(char _id[2])
{
}

void tambahBukuTersedia(int index, char _id[2], char _jenis[50], char _judul[50])
{
    struct BukuModel _buku;
    strcpy(_buku.id, _id);
    strcpy(_buku.jenis, _jenis);
    strcpy(_buku.judul, _judul);

    bukuTersedia[index] = _buku;
}

void loadDummyData()
{
    tambahBukuTersedia(0, "A1", "Pemrograman", "Trick for C++");
    tambahBukuTersedia(1, "A2", "Sastra Jepang", "Katakana & Kanji 2");
    tambahBukuTersedia(2, "A3", "Teknologi", "Cisco Networking");
    tambahBukuTersedia(3, "A4", "Matematika", "Statistika jilid 2");
    tambahBukuTersedia(4, "A5", "Sains & physics", "Anatomi Tubuh  Manusia");
}

int main()
{
    loadDummyData();
}