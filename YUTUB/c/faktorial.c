// 5! = 5 x 4 x 3 x 2 x 1 = 120
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int input;
    printf("Masukkan sebuah bilangan bulat?\n");
    scanf("%d", &input);

    printf("%d! =", input);

    int res = 1;
    for (int i = input; i > 0; i--)
    {
        printf(" %d ", i);

        res = res * i;

        if (i != 1)
        {
            printf("x");
        }
    }

    printf("= %d\n", res);

    return 0;
}
