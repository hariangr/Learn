#include <stdio.h>

int main(int argc, char const *argv[])
{
    int const length = 4;
    int arrA[length] = {1, 2, 3, 4};
    int arrB[length] = {5, 6, 7, 8};
    int hasil[length];

    // Untuk menambahkan
    for (int i = 0; i < length; i++)
    {
        hasil[i] = arrA[i] + arrB[i];
    }

    // Untuk ngeprint
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", hasil[i]);
    }

    return 0;
}
