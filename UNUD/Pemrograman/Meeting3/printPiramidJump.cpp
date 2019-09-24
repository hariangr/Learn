#include <stdio.h>

int main()
{
    int max;
    scanf("%d", &max);

    for (int i = 1; i <= max; i++)
    {
        for (int j = 0; j < (i * 2 - 1); j++)
        {
            printf("*");
        }

        printf("\n");
    }
}