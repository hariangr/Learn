#include <stdio.h>

int n = 3;

int main()
{
    // printf("Masukan sebuah angka\n");
    // scanf("%d", &n);

    int hLength = n * 2 - 1;
    for (int row = 1; row <= n; row++)
    {
        int starCount = 2 * row - 1;

        for (int i = 1; i <= (hLength - starCount) / 2; i++)
        {
            printf(" ");
        }

        for (int i = 1; i <= starCount; i++)
        {
            printf("*");
        }

        for (int i = 1; i <= (hLength - starCount) / 2; i++)
        {
            printf(" ");
        }

        printf("\n");
    }

    return 0;
}

/* OUTPUT 

  *  
 *** 
*****  

*/