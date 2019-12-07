#include <stdio.h>

void print2DMatrix(int *arrA, int height, int width)
{
    for (int baris = 0; baris < height; baris++)
    {
        for (int kolom = 0; kolom < width; kolom++)
        {
            printf("%d\t", arrA[(baris * width) + kolom]);
        }
        printf("\n");
    }
}

int calculateValueAt(int *arrA, int heightA, int widthA, int *arrB, int heightB, int widthB, int x, int y)
{
    int sum = 0;
    for (int i = 0; i < widthA; i++)
    {
        int __a = arrA[(widthA * y) + i];
        int __b = arrB[(widthB * i) + x];

        sum = sum + (__a * __b);
    }

    return sum;
}

void matrixMultiply(int *arrA, int heightA, int widthA, int *arrB, int heightB, int widthB, int *arrRes)
{
    for (int baris = 0; baris < heightA; baris++)
    {
        for (int kolom = 0; kolom < widthB; kolom++)
        {
            arrRes[(widthB * baris) + kolom] = calculateValueAt(arrA, heightA, widthA, arrB, heightB, widthB, kolom, baris);
        }
    }
}

#define heightA 3
#define widthA 3
#define heightB 3
#define widthB 2

int main()
{
    int arrA[heightA][widthA] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arrB[heightB][widthB] = {{6, 5}, {4, 3}, {2, 1}};

    int *_arrA = &arrA[0][0];
    int *_arrB = &arrB[0][0];

    int res[heightA][widthB];
    int *resPointer = &res[0][0];

    matrixMultiply(_arrA, heightA, widthA, _arrB, heightB, widthB, resPointer);
    print2DMatrix(resPointer, heightA, widthB);

    return 0;
}
