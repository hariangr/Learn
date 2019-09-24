#include <stdio.h>
#include <string.h>

int main()
{
    int max;
    scanf("%d", &max);

    for (int row = 1; row <= max; row++)
    {
        // Print spasi
        for (int i = 0; i < max - row; i++)
        {
            printf(" ");
        }

        // Print *
        for (int i = 1; i <= row; i++)
        {
            printf("*");
        }

        printf("\n");
    }
}