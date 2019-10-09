#include <stdio.h>
#include <stdlib.h>

// Pertambahan matrix 1 dimensi

int main()
{
    int l = 5;
    int arrA[l];
    int arrB[l];

    for (int i = 0; i < l; i++)
    {
        arrA[i] = (i + 3) * 2;
        arrB[i] = 10 - i;
    }

    int hasil[l];

    for (int i = 0; i < l; i++)
    {
        hasil[i] = arrA[i] + arrB[i];
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d + %d = %d\n", arrA[i], arrB[i], hasil[i]);
    }

    return 0;
}