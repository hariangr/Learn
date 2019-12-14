#include <stdio.h>

#define jum 10

// int source[jum] = {3, 5, 2, 1, 6};
int source[jum] = {3, 5, 2, 1, 6, 1, 100, 88, 33, 0};

void printArr()
{
    printf("\n");
    for (int i = 0; i < jum; i++)
    {
        printf("%d ", source[i]);
    }
}

void swap(int indexA, int indexB)
{
    int temp = source[indexA];
    source[indexA] = source[indexB];
    source[indexB] = temp;
}

void insertionSort()
{
    for (int i = 1; i < jum; i++)
    {
        int pos = i;

        if (source[i] > source[i - 1])
        {
            continue;
        }

        for (int j = i - 1; j >= 0; j--)
        {
            if (source[pos] < source[j])
            {
                swap(pos, j);
                pos = j;
                printArr();
            }
        }
    }
}
int main()
{
    printArr();

    insertionSort();

    printArr();
}