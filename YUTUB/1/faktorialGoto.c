#include <stdio.h>

int main(int argc, char const *argv[])
{
    int input;
    printf("Masukkan angka yang mau dicari faktorialnya?\n");
    scanf("%d", &input);

    printf("%d! =", input);

    int res = 1;
    int i = input;

perulangan:
    res = res * i;
    printf(" %d ", i);

    if (i > 1)
    {
        printf("x");
    }

    if (i > 1)
    {
        i--;
        goto perulangan;
    }

    printf("= %d\n", res);

    return 0;
}
