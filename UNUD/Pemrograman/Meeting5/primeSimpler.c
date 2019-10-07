#include <stdio.h>

int n = 5;
int main()
{
    printf("Masukkan sebuah bilangan bulat: \n");
    scanf("%d", &n);

    int _divisibleBy = 0;
    for (int i = 1; i <= n; i = i + 1)
    {
        if (n % i == 0)
        {
            _divisibleBy++;
        }
    }

    if (_divisibleBy == 2)
    {
        printf("%d adalah bilangan prima\n", n);
    }
    else
    {
        printf("%d bukan bilangan prima\n", n);
    }

    return 0;
}