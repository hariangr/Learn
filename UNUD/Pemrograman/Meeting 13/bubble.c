#include <stdio.h>

void swap(int **p1, int **p2)
{
    // int pTemp = p1;
    // p1 = p2;
    // p2 = pTemp;

    printf("%d", p1);
}

void printArray(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int bubbleSortHelper(int *arr, int length)
{
    int counter = 0;

    for (int i = 0; i < (length - 1); i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(&arr[i], &arr[i + 1]);
            counter++;
        }
    }

    return counter;
}

void bubbleSort(int *firstItem, int length)
{
    while (1 > 0)
    {
        int counter = bubbleSortHelper(firstItem, length);
        printf("\n== %d", counter);

        if (counter == 0)
        {
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {5, 3, 5, 7, 9, 6, 4, 23, 6};
    int length = 9;

    printArray(&arr[0], length);

    // bubbleSort(&arr[0], length);
    swap(&arr[0], &arr[1]);

    printArray(&arr[0], length);

    return 0;
}
