#include <stdio.h>
#include <stdlib.h>

int main()
{
    int P1, L1;

    printf("masukkan panjang matrix 1 'a'x'b' : \n");
    scanf("%d %d", &P1, &L1);
    int matrixA[P1][L1];

    int P2, L2;
    printf("masukkan panjang matrix 2 'a'x'b' : \n");
    scanf("%d %d", &P2, &L2);
    int matrixB[P2][L2];

    if (L1 != P2)
    {
        printf("Tidak Bisa dikalikan");
        return 1;
    }

    // Menginput Semua nilai matrix 2d
    for (int a = 0; a < P1; a++)
    {
        for (int b = 0; b < L1; b++)
        {
            printf("masukkan nilai matrix1 row ke %d Kolom ke %d = ", a + 1, b + 1);
            scanf("%d", &matrixA[a][b]);
        }
    }

    // Print Preview Matrix 1
    for (int a = 0; a < P1; a++)
    {
        printf("{");
        for (int b = 0; b < L1; b++)
        {
            printf(" %d ", matrixA[a][b]);
        }
        printf("}\n");
    }

    // Menghitung Baris dan kolom matrix 2
    for (int a = 0; a < P2; a++)
    {
        for (int b = 0; b < L2; b++)
        {
            printf("masukkan nilai matrix2 row ke %d Kolom ke %d = ", a + 1, b + 1);
            scanf("%d", &matrixB[a][b]);
        }
    }

    // Print Preview matrix 2
    for (int a = 0; a < P2; a++)
    {
        printf("{");
        for (int b = 0; b < L2; b++)
        {
            printf(" %d ", matrixB[a][b]);
        }
        printf("}\n");
    }

    // Membuat Matrix hasil
    int L3 = P1;
    int matrixRes[10][10]; // << kayaknya yg pas eksperimen
    printf("\n\nMatrix Hasil Adalah :\n");

    for (int a = 0; a < L3; a++)
    {
        printf("{");
        for (int b = 0; b < L2; b++)
        {
            int e = 0;
            for (int c = 0; c < P2; c++)
            {
                e = e + matrixA[a][c] * matrixB[c][b];
            }
            matrixRes[a][b] = e;
            printf(" %d ", matrixRes[a][b]);
        }
        printf("}\n");
    }

    return 0;
}