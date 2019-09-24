#include <stdio.h>
#include <string.h>

void printPlus(int max)
{
    for (int i = 1; i <= max; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

void printMin(int from, int min)
{
    int x = from - min;
    for (int i = from; i >= min; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

int main()
{
    int max;
    scanf("%d", &max);

    int midpoint = (max / 2) + 1;

    printf("%d\n", midpoint);

    printPlus(midpoint);
    printMin(midpoint - 1, 1);
}
