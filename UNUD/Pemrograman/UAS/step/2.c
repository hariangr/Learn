// Baca data master.txt

#include <stdio.h>

void bacaData()
{
    FILE *reader;
    reader = fopen("master.txt", "r");

    char _sex;
    int _age;
    int _studytime;
    int _absence;
    int _g1;
    int _g2;
    int _g3;

    while (!feof(reader))
    {
        fscanf(reader, "%c %d %d %d %d %d %d\n", &_sex, &_age, &_studytime, &_absence, &_g1, &_g2, &_g3);
        printf("%c %d %d %d %d %d %d\n", _sex, _age, _studytime, _absence, _g1, _g2, _g3);
    }
}

void pilihanMenu()
{
    printf("[MENU SELECTION]\n");
    printf("> 1. Tampilkan semua data tersimpan\n");
    printf("> 2. Import data dari sebuah file\n");
    printf("> 3. Export data laki-laki\n");
    printf("> 4. Export data perempuan\n");
    printf("> 5. Tampilkan 20 data GP3\n");

    int menu;
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        printf("Menu pertama");
        break;
    case 2:
        printf("Menu kedua");
        break;
    case 3:
        printf("Menu ketiga");
        break;
    case 4:
        printf("Menu keempat");
        break;
    case 5:
        printf("Menu kelima");
        break;
    default:
        printf("Error\n");
        break;
    }
}

int main()
{
    // pilihanMenu();
    bacaData();
}