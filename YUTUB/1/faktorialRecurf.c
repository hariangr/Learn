#include <stdio.h>

void recurf(int cur, int sum)
{

    if (cur == 0)
    {
        printf("= %d\n", sum);
        return;
    }
    else if (cur > 0)
    {
        printf(" %d ", cur);

        if (cur > 1)
        {
            printf("x");
        }

        recurf(cur - 1, sum * cur);
    }
}

int main(int argc, char const *argv[])
{
    int input;
    printf("Masukkan angka yang mau dicari faktorialnya?\n");
    scanf("%d", &input);

    printf("%d! =", input);

    recurf(input, 1);

    // int res = 1;

    // printf("= %d\n", res);

    return 0;
}
