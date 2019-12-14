#include <stdio.h>

void printInfoOrang(char nama[100], char jenis_kelamin, int umur)
{
    printf("Info dari orang\n");
    printf("> Nama adalah: %s\n", nama);
    printf("> Jenis kelamin: %c\n", jenis_kelamin);
    printf("> Umur adalah: %d\n", umur);
}

int main()
{
    FILE *reader = fopen("15_file_read_data.txt", "r");

    while (!feof(reader))
    {
        char nama[100];
        char jenis_kelamin;
        int umur;

        fscanf(reader, "%s %c %d\n", &nama[0], &jenis_kelamin, &umur);

        printInfoOrang(nama, jenis_kelamin, umur);
    }
}