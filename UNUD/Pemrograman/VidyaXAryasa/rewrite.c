#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct BukuModel
{
    char id[5];
    char jenis[50];
    char judul[50];
};

struct BukuModel bukuTersedia[5];

int getIndexByBookId(char _id[5])
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

bool cekIdSudahAda(char _id[5])
{
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

void tambahBukuTersedia(int _index, char _id[2], char _jenis[50], char _judul[50])
{
    struct BukuModel _buku;
    strcpy(_buku.id, _id);
    strcpy(_buku.jenis, _jenis);
    strcpy(_buku.judul, _judul);

    bukuTersedia[_index] = _buku;
}

void loadDummyData()
{
    tambahBukuTersedia(0, "A1", "Pemrograman", "Trick for C++");
    tambahBukuTersedia(1, "A2", "Sastra Jepang", "Katakana & Kanji 2");
    tambahBukuTersedia(2, "A3", "Teknologi", "Cisco Networking");
    tambahBukuTersedia(3, "A4", "Matematika", "Statistika jilid 2");
    tambahBukuTersedia(4, "A5", "Sains & physics", "Anatomi Tubuh  Manusia");
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

int main()
{
    loadDummyData();
    printSemuaBukuTersedia();

    printf("%d\n", getIndexByBookId("A6"));
}