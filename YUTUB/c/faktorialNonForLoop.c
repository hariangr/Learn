// 5! = 5 x 4 x 3 x 2 x 1 = 120
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int input;
    printf("Masukkan sebuah bilangan bulat?\n");
    scanf("%d", &input);

    printf("%d! =", input);

    int res = 1;

    int i = input;

perulangan:
    res = res * i;

    printf(" %d ", i);
    if (i != 1)
    {
        printf("x");
    }

    i = i - 1;
    if (i != 0)
    {
        goto perulangan;
    }

    printf("= %d\n", res);

    return 0;
}
