#include <stdio.h>

void recurf(int x)
{
    if (x == 0)
    {
        printf("0");
    }
    else
    {
        int bin = x % 2;
        if (x != 1)
        {
            if (bin == 0)
            {
                recurf(x / 2);
            }
            else
            {
                recurf((x - 1) / 2);
            }
        }
        printf("%d", bin);
    }
}

int main(int argc, char const *argv[])
{
    int i;
    printf("Masukkan binary yang ingin dicari:\n");
    scanf("%d", &i);

    recurf(i);
    return 0;
}
