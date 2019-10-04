#include <stdio.h>

int a = 0;

int main()
{
    while (1)
    {
        int _input;
        printf("Masukkan nilai?\n");
        scanf("%d", &_input);

        if (_input == 0)
        {
            break;
        }
        else
        {
            a += _input;
        }
    }


    printf("Total nilai yang kamu masukan adalah %d\n", a);
}