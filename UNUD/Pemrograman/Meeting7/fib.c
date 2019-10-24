#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i;
    printf("Masukkan posisi fibonaci yang ingin dicari (1,1,2...):\n");
    scanf("%d", &i);

    int temp[99999];
    temp[0] = 1;
    temp[1] = 1;

    for (int j = 2; j < i; j++)
    {
        temp[j] = temp[j - 1] + temp[j - 2];
        // printf("%d\n", temp[j]);
    }

    printf("%d\n", temp[i - 1]);

    return 0;
}

// 1 2 3 4 5 6 7  8
// 1 1 2 3 5 8 13 21 