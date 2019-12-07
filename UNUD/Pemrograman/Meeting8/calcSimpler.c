#include <stdio.h>

int inputA()
{
    int bilA;
    printf("Masukkan bilangan pertama: ");
    scanf("%d", &bilA);

    return bilA;
}

int inputB()
{
    int bilB;
    printf("Masukkan bilangan kedua: ");
    scanf("%d", &bilB);

    return bilB;
}

int menuSelection()
{
    int menu;

    printf("1. Perkalian\n");
    printf("2. Pembagian\n");
    printf("3. Pengurangan\n");
    printf("4. Penjumlahan\n");
    printf("Pilih menu yang ingin dipilih? (1/2/3/4) ");

    scanf("%d", &menu);

    if (menu < 1 || menu > 4)
    {
        printf("Menu yang dipilih tidak valid!\n");
        return menuSelection();
    }
    else
    {
        return menu;
    }
}

float doMath(int _a, int _b, int _menu)
{
    float _res;
    char _operator;

    switch (_menu)
    {
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
    }

    printf("\t==> %d %c %d = %f\n", _a, _operator, _b, _res);
    return _res;
}

int main()
{
    int _menu = menuSelection();
    int _a = inputA();
    int _b = inputB();

    doMath(_a, _b, _menu);

    char _again[1];
    printf("Kembali ke menu? (y/n) ");
    scanf("%s", _again);

    if (_again[0] == 'y' || _again[0] == 'Y')
    {
        printf("\n\n");
        return main();
    }

    return 0;
}
