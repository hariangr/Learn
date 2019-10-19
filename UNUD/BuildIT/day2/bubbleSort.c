#include <stdio.h>
#include <stdbool.h>

int const length = 16;
int source[length] = {3, 5, 2, 3, 1, 285, 2, 5, 1, 24, 5, 6, 6, 3, 12, 2};

void swap(int indexA, int indexB)
{
    int temp = source[indexB];
    source[indexB] = source[indexA];
    source[indexA] = temp;
}

void bubbleSort()
{
    while (true)
    {
        int counter = 0;

        for (int i = 0; i < length - 1; i++)
        {
            if (source[i] > source[i + 1])
            {
                swap(i, i + 1);
                counter++;
            }
        }

        if (counter == 0)
        {
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("Int size is %d \n", (int)sizeof(int));
    printf("Array size is %d \n", (int)sizeof(source));

    printf("Source: \n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", source[i]);
    }

    bubbleSort();

    printf("Sorted: \n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", source[i]);
    }

    printf("\n");
}
