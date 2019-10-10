#include <stdio.h>

int res = 0;

int main()
{
    while (1 > 0)
    {
        printf("Masukan input:\n");
        int _x;
        scanf("%d", &_x);

        if (_x != 0)
        {
            res = res + _x;
        }
        else
        {
            break;
        }
    }

    printf("Total input: %d\n", res);

    return 0;
}