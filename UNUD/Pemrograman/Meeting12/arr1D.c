#include <stdio.h>

int main()
{
    // int x = 5;

    // printf("%d\n", x);

    // int arr[5] = {4, 5, 6, 7, 8};

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d\n", arr[i]);
    // }

    int arr[2][3] = {{3, 5, 7}, {1, 2, 3}};

    for (int baris = 0; baris < 2; baris++)
    {
        for (int kolom = 0; kolom < 3; kolom++)
        {
            printf("%d ", arr[baris][kolom]);
        }

        printf("\n");
    }

    return 0;
}
