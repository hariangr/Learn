#include <stdio.h>

int n = 5;
int main()
{
    printf("Masukkan sebuah bilangan bulat: \n");
    scanf("%d", &n);

    int res = 1;
    printf("\n\n%d! =", n);

    for (int i = n; i >= 1; i--)
    {
        printf(" %d ", i);

        res = res * i;
        if (i != 1)
            printf("x");
    }

    printf("= %d\n", res);
    return 0;
}

// What if negative number?