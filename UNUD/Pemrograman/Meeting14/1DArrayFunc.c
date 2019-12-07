#include <stdio.h>

void print1DMatrix(int *firstItem, int panjang)
{
    for (int i = 0; i < panjang; i++)
    {
        printf("Item nilainya %d\n", *firstItem);
        firstItem++;
    }
    
}

int main()
{
    int matriks[] = {1, 2, 3};

    print1DMatrix(&matriks[0], 3);

    return 0;
}
