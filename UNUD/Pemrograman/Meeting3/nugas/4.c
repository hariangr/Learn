#include <stdio.h>

int n = 3;

void printStar(int hLength, int startLength)
{
    for (int i = 1; i <= (hLength - startLength) / 2; i++)
    {
        printf(" ");
    }

    for (int i = 1; i <= startLength; i++)
    {
        printf("*");
    }

    for (int i = 1; i <= (hLength - startLength) / 2; i++)
    {
        printf(" ");
    }

    printf("\n");
}

int main()
{
    int hLength = n * 2 - 1;
    for (int row = 1; row <= n; row++)
    {
        int starCount = 2 * row - 1;
        printStar(hLength, hLength - starCount + 1);
    }

    for (int row = 2; row <= n; row++)
    {
        int starCount = 2 * row - 1;
        printStar(hLength, starCount);
    }

    return 0;
}

/*

*****
 *** 
  *  
 *** 
*****

 */
