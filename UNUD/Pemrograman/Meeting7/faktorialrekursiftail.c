#include <stdio.h>

void recurf(int cur, int sum)
{
    if (cur == 0)
    {
        printf("= %d\n", sum);
        return;
    }

    sum = sum * cur;
    printf(" %d ", cur);

    if (cur > 1)
    {
        printf("x");
    }

    recurf(cur - 1, sum);
}

int main(int argc, char const *argv[])
{
    int i;
    printf("Masukkan faktorial yang ingin dicari:\n");
    scanf("%d", &i);

    printf("%d! =", i);
    recurf(i, 1);

    return 0;
}
