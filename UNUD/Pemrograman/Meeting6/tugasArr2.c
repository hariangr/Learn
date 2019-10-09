#include <stdio.h>
const int longestDimension = 3;
const int height = 3, width = 3;

void print2DArray(int arr[longestDimension][longestDimension])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%d", arr[i][j]);

            if (j != width)
                printf("\t");
        }

        if (i != height)
            printf("\n");
    }
}

int calcMatrixMultPerItem(int arrA[height][width], int arrB[width][height], int l, int y, int x)
{
    int res = 0;
    for (int i = 0; i < l; i++)
    {
        res += arrA[y][i] * arrB[i][x];
    }

    return res;
}

int main(int argc, char const *argv[])
{
    int hasil[longestDimension][longestDimension];

    int arrA[height][width] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int arrB[width][height] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1},
    };

    for (int y = 0; y < longestDimension; y++)
    {
        for (int x = 0; x < longestDimension; x++)
        {
            hasil[y][x] = calcMatrixMultPerItem(arrA, arrB, longestDimension, y, x);
        }
    }
    print2DArray(hasil);

    return 0;
}
