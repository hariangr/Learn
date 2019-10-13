#include <stdio.h>

int main()
{
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int H[2][2] = {{0, 0}, {0, 0}};

    for (int baris = 0; baris < 2; baris++)
    {
        for (int kolom = 0; kolom < 3; kolom++)
        {
            int temp = 0;
            for (int i = 0; i < 3; i++)
            {
                temp += A[baris][i] * B[i][kolom];
            }
            H[baris][kolom] = temp;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", H[i][j]);
        }
        printf("\n");
    }

    return 0;
}