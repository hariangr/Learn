// 5! = 5x4x3x2x1 = 120
// 4! = 4x3x2x1 = 24

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int input;
    printf("Masukkan angka yang mau dicari faktorialnya?\n");
    scanf("%d", &input);

    printf("%d! =", input);

    int res = 1;

    for (int i = input; i > 0; i--)
    {
        res = res * i;
        printf(" %d ", i);

        if (i > 1)
        {
            printf("x");
        }
    }

    printf("= %d\n", res);

    return 0;
}
