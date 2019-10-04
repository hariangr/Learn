#include <stdio.h>

int res = 0;

int main()
{
    while (1 > 0)
    {
        printf("Masukan input:\n");
        int _x;
        scanf("%d", &_x);

        if (_x == 0)
        {
            break;
        }
        else
        {
            res = res + _x;
        }
    }

    printf("Total input: %d\n", res);

    return 0;
}