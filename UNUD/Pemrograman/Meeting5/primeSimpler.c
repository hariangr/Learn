#include <stdio.h>

int n = 5;
int main()
{
    printf("Masukan angka?\n");
    scanf("%d", &n);

    int _divisibleBy = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            _divisibleBy++;
        }
    }

    if (_divisibleBy == 2)
    {
        printf("Prima\n");
    }
    else
    {
        printf("Non\n");
    }

    return 0;
}