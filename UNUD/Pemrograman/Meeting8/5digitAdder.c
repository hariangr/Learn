#include <stdio.h>

int main(int argc, char const *argv[])
{
    char cont[5];
    printf("Masukkan angka? ");
    scanf("%s", cont);

    int _adder = 0;
    for (int i = 0; i < 5; i++)
    {
        int asciiToInt = ((int)cont[i]) - 48;
        _adder += asciiToInt;
    }

    printf("Hasil yaitu %d\n", _adder);
}
