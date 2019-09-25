#include <stdio.h>
#include <string.h>

/*

9
8
        *********
       **********
      ***********
     ************
    *************
   **************
  ***************
 ****************
*****************

*/

int main()
{
    int max;
    scanf("%d", &max);
    int rightPad;
    scanf("%d", &rightPad);

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

        for (int i = 1; i <= rightPad; i++)
        {
            printf("*");
        }

        printf("\n");
    }
}