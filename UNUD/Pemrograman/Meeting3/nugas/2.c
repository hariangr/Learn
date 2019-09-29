#include <stdio.h>

int n = 3;

int main()
{
    int max = n;
    int rightPad = n;
    // scanf("%d", &max);
    // scanf("%d", &rightPad);

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

        // Print right padded *
        for (int i = 1; i <= rightPad; i++)
        {
            printf("*");
        }

        printf("\n");
    }
}

/*

  ****
 *****
******

*/