#include <stdio.h>

/*
        *        
       ***       
      *****      
     *******     
    *********    
   ***********   
  *************  
 *************** 
*****************
*/

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
    // printf("Masukan bilangan ganjil:\n");
    int maxLine;
    // scanf("%d", &maxLine);

    maxLine = 3; // Nilai n di papan

    if (maxLine % 2 == 0)
    {
        printf("Harus bilangan ganjil");
        return main();
    }

    int hLength = maxLine * 2 - 1;
    for (int row = 1; row <= maxLine; row++)
    {
        int starCount = 2 * row - 1;
        printStar(hLength, starCount);
    }

    return 0;
}
