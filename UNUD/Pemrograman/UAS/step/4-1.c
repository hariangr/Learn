// Cara kerja structnya

#include <stdio.h>

int indexTerakhirTerisi = 0;

typedef struct
{
    char sex;
    int age;
    int studytime;
    int absence;
    int g1;
    int g2;
    int g3;
} Mahasiswa;

// char arrSex[999999];
// int arrAge[999999];
// int arrStudyTime[999999];
// int arrAbsence[999999];
// int arrG1[999999];
// int arrG2[999999];
// int arrG3[999999];

// void bacaData()
// {
//     FILE *reader;
//     reader = fopen("master.txt", "r");

//     char _sex;
//     int _age;
//     int _studytime;
//     int _absence;
//     int _g1;
//     int _g2;
//     int _g3;

//     while (!feof(reader))
//     {
//         fscanf(reader, "%c %d %d %d %d %d %d\n", &_sex, &_age, &_studytime, &_absence, &_g1, &_g2, &_g3);

//         arrSex[totalSiswa] = _sex;
//         arrAge[totalSiswa] = _age;
//         arrStudyTime[totalSiswa] = _studytime;
//         arrAbsence[totalSiswa] = _absence;
//         arrG1[totalSiswa] = _g1;
//         arrG2[totalSiswa] = _g2;
//         arrG3[totalSiswa] = _g3;
//         totalSiswa++;
//     }
// }

// void pilihanMenu()
// {
//     printf("[MENU SELECTION]\n");
//     printf("> 1. Tampilkan semua data tersimpan\n");
//     printf("> 2. Import data dari sebuah file\n");
//     printf("> 3. Export data laki-laki\n");
//     printf("> 4. Export data perempuan\n");
//     printf("> 5. Tampilkan 20 data GP3\n");

//     int menu;
//     scanf("%d", &menu);

//     switch (menu)
//     {
//     case 1:
//         printf("Menu pertama");
//         break;
//     case 2:
//         printf("Menu kedua");
//         break;
//     case 3:
//         printf("Menu ketiga");
//         break;
//     case 4:
//         printf("Menu keempat");
//         break;
//     case 5:
//         printf("Menu kelima");
//         break;
//     default:
//         printf("Error\n");
//         break;
//     }
// }

int main()
{
    // pilihanMenu();
    // bacaData();

    // for (int i = 0; i < totalSiswa; i++)
    // {
    //     printf("%c %d %d %d %d %d %d\n", arrSex[i], arrAge[i], arrStudyTime[i], arrAbsence[i], arrG1[i], arrG2[i], arrG3[i]);
    // }

    Mahasiswa videv;
    videv.sex = 'F';
    videv.age = 19;
    videv.studytime = 13;
    videv.absence = 2;
    videv.g1 = 99;
    videv.g2 = 100;
    videv.g3 = 80;

    printf("Umur videv adalah %d\n", videv.age);
    printf("Studytime videv adalah %d\n", videv.studytime);
}