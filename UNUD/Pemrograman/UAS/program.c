#include <stdio.h>
#include <stdbool.h>
#include "student.h"
#include <string.h>

int total_student = 0;
struct Student students[__INT_MAX__];

/// TODO: Cara mereturn struct array dari function
struct StudentsContainer readedDatasetsBuffer;
void loadDatasets(char *filePath, bool skipFirstLine)
{
    int item_readed = 0;

    FILE *reader = fopen(filePath, "r");

    while (!feof(reader))
    {
        struct Student _s;
        fscanf(reader, "%c %d %d %d %d %d %d\n", &_s.sex, &_s.age, &_s.studytime, &_s.absence, &_s.g1, &_s.g2, &_s.g3);
        readedDatasetsBuffer.students[item_readed] = _s;

        item_readed++;
    }

    readedDatasetsBuffer.number = item_readed;

    fclose(reader);
}

void bubbleSortG3(int length, struct Student *source, struct Student *result, bool isAsc)
{
    for (int i = 0; i < length; i++)
    {
        result[i] = source[i];
    }

    while (true)
    {
        int counter = 0;

        for (int i = 0; i < length - 1; i++)
        {
            if (isAsc)
            {
                if (result[i].g3 < result[i + 1].g3)
                {
                    struct Student temp = result[i + 1];
                    result[i + 1] = result[i];
                    result[i] = temp;
                    counter++;
                }
            }
            else
            {
                if (result[i].g3 > result[i + 1].g3)
                {
                    struct Student temp = result[i + 1];
                    result[i + 1] = result[i];
                    result[i] = temp;
                    counter++;
                }
            }
        }

        if (counter == 0)
        {
            return;
        }
    }
}

void importStudentArray()
{
    printf("Importing %d data\n", readedDatasetsBuffer.number);

    for (int i = 0; i < readedDatasetsBuffer.number; i++)
    {
        students[total_student] = readedDatasetsBuffer.students[i];
        total_student++;
    }
}

void createAndSaveData(struct Student _s)
{
    FILE *writer = fopen("master.txt", "a");
    fprintf(writer, "%c %d %d %d %d %d %d\n", _s.sex, _s.age, _s.studytime, _s.absence, _s.g1, _s.g2, _s.g3);
    fclose(writer);
}

void hMenuOneShowAll()
{
    for (int i = 0; i < total_student; i++)
    {
        struct Student _s = students[i];
        printf("%c %d %d %d %d %d %d\n", _s.sex, _s.age, _s.studytime, _s.absence, _s.g1, _s.g2, _s.g3);
    }

    printf("Menampilkan %d data\n", total_student);
}

void hMenuTwoImport()
{
    char _filePath[255];
    printf("Masukkan nama file dan ekstensinya? (Misal next1.txt) ");
    fflush(stdin);
    scanf("%s", _filePath);

    loadDatasets(_filePath, false);
    printf("Import %d of data? (y/n) ", readedDatasetsBuffer.number);
    char confirm;
    fflush(stdin);
    scanf("%c", &confirm);

    if (confirm != 'Y' && confirm != 'y')
    {
        printf("Abort\n");
        return;
    }

    importStudentArray();
}

void hMenuThreeExportMale()
{
    FILE *writer = fopen("male.txt", "w");

    for (int i = 0; i < total_student; i++)
    {
        struct Student _s = students[i];
        if (_s.sex == 'M')
        {
            fprintf(writer, "%c %d %d %d %d %d %d\n", _s.sex, _s.age, _s.studytime, _s.absence, _s.g1, _s.g2, _s.g3);
        }
    }

    fclose(writer);
}

void hMenuFourExportFemale()
{
    FILE *writer = fopen("female.txt", "w");

    for (int i = 0; i < total_student; i++)
    {
        struct Student _s = students[i];
        if (_s.sex == 'F')
        {
            fprintf(writer, "%c %d %d %d %d %d %d\n", _s.sex, _s.age, _s.studytime, _s.absence, _s.g1, _s.g2, _s.g3);
        }
    }

    fclose(writer);
}

void hMenuFiveGP3()
{
    printf("---\n");
    printf("1. 20 GP3 teratas\n");
    printf("2. 20 GP3 terbawah\n");
    int _menu;
    scanf("%d", &_menu);

    bool _isAsc;
    if (_menu == 1)
    {
        _isAsc = true;
    }
    else if (_menu == 2)
    {
        _isAsc = false;
    }
    else
    {
        printf("Abort\n");
        return;
    }

    struct Student sortedByGP3[total_student];
    bubbleSortG3(total_student, &students[0], &sortedByGP3[0], _isAsc);

    for (int i = 0; i < 20; i++)
    {
        struct Student _s = sortedByGP3[i];
        printf("%d. %c %d %d %d %d %d %d\n", i + 1, _s.sex, _s.age, _s.studytime, _s.absence, _s.g1, _s.g2, _s.g3);
    }
}

void menuSelection()
{
    printf("[MENU SELECTION]\n");
    printf("> 1. Tampilkan semua data tersimpan\n");
    printf("> 2. Import data dari sebuah file\n");
    printf("> 3. Export data laki-laki\n");
    printf("> 4. Export data perempuan\n");
    printf("> 5. Tampilkan 20 data GP3\n");

    printf("Pilih menu yang ingin dipilih? ");
    int _menu;
    scanf("%d", &_menu);

    switch (_menu)
    {
    case 1:
        hMenuOneShowAll();
        break;
    case 2:
        hMenuTwoImport();
        break;
    case 3:
        hMenuThreeExportMale();
        break;
    case 4:
        hMenuFourExportFemale();
        break;
    case 5:
        hMenuFiveGP3();
        break;
    default:
        break;
    }
}

int main()
{
    loadDatasets("master.txt", false);
    importStudentArray();

    while (true)
    {
        menuSelection();
    }

    // struct Student _n = {'M', 99, 12, 0, 10, 10, 0};
    // createAndSaveData(_n);
}