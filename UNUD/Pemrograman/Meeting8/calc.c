#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int bilA;
int bilB;
int menu;

void input()
{
    printf("Masukkan bilangan pertama: ");
    scanf("%d", &bilA);

    printf("Masukkan bilangan kedua: ");
    scanf("%d", &bilB);
}

void menuSelection(bool allowInputChange)
{
    if (allowInputChange)
    {
        printf("0. Ubah input\n");
    }

    printf("1. Perkalian\n");
    printf("2. Pembagian\n");
    printf("3. Pengurangan\n");
    printf("4. Penjumlahan\n");
    printf("9. Keluar\n");
    printf("Pilih menu yang ingin dipilih? (0/1/2/3/4/9) ");

    scanf("%d", &menu);

    if (menu != 9 && (menu < 1 || menu > 4))
    {
        if (menu != 0 && allowInputChange == false)
        {
            printf("Menu yang dipilih tidak valid!\n");
            menuSelection(allowInputChange);
        }
    }
}

// void shouldRetry()
// {
//     char retry;
//     printf("Ingin mencoba menu yang lain? (y/n)");
//     scanf("%c", &retry);

//     printf("%c", retry);
//     if (retry == 'y' || retry == 'Y')
//     {
//         main();
//     }
// }

float doMath(int _a, int _b, int _menu)
{
    float _res;
    char _operator;

    switch (_menu)
    {
    case 0:
        // Ubah input
        input();
        break;
    case 1:
        // Kali
        _res = _a * _b;
        _operator = '*';
        break;
    case 2:
        // Bagi
        _res = (float)_a / (float)_b;
        _operator = '/';
        break;
    case 3:
        // Kurang
        _res = _a - _b;
        _operator = '-';
        break;
    case 4:
        // Tambah
        _res = _a + _b;
        _operator = '+';
        break;
    case 9:
        // Keluar
        exit(0);
        break;
    default:
        printf("Something went wrong\n");
        return -0;
        break;
    }

    printf("==> %d %c %d = %f\n", _a, _operator, _b, _res);
    return 0;
}

int main()
{
    bool firstTime = true;
    input();
    menuSelection(false);

    while (true)
    {
        if (firstTime == false)
        {
            menuSelection(true);
        }
        doMath(bilA, bilB, menu);
        firstTime = false;
        printf("\n_________________________\n\n");
    }
    return 0;
}
