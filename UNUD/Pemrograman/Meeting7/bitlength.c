#include <stdio.h>

int counter = 0;
void recurf(int x)
{
    if (x == 0)
    {
        printf("0");
        counter += 1;
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
        counter += 1;
    }
}

int main(int argc, char const *argv[])
{
    int i;
    printf("Masukkan binary yang ingin dicari:\n");
    scanf("%d", &i);

    recurf(i);
    printf("\nPanjang biner adalah %d\n", counter);
    return 0;
}
