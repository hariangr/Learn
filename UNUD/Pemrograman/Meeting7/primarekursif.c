#include <stdio.h>

void recurf(int input, int cur, int divisibleBy)
{
    if (cur == 0)
    {
        if (divisibleBy == 2)
        {
            printf("Bilangan prima\n");
        }
        else
        {
            printf("Bukan bilangan prima\n");
        }

        return;
    }

    if (input % cur == 0)
    {
        recurf(input, cur - 1, divisibleBy + 1);
    }
    else
    {
        recurf(input, cur - 1, divisibleBy);
    }
}

int main(int argc, char const *argv[])
{
    int i;
    printf("Masukkan angka yang ingin dicari apakah prima:\n");
    scanf("%d", &i);

    recurf(i, i, 0);
    return 0;
}
