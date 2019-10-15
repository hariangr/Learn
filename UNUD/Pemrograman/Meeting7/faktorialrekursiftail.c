#include <stdio.h>

void recurf(int cur, int sum)
{
    if (cur == 0)
    {
        printf("= %d\n", sum);
        return;
    }

    sum = sum * cur;
    printf("%d ", cur);

    recurf(cur - 1, sum);
}

int main(int argc, char const *argv[])
{
    int i;
    printf("Masukkan faktorial yang ingin dicari:\n");
    scanf("%d", &i);

    recurf(i, 1);

    /* code */
    return 0;
}
