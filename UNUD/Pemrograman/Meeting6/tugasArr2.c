#include <stdio.h>

int main()
{
    int l = 5;
    int arrA[] = {2, 3, 4, 5, 2};
    int arrB[] = {3, 4, 3, 2, 2};

    int hasil[l];
    int res = 0;

    for (int i = 0; i < 5; i++)
    {
        hasil[i] = arrA[i] + arrB[i];
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d + %d = %d\n", arrA[i], arrB[i], hasil[i]);
    }

    return 0;
}