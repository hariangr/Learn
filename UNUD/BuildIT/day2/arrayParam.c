#include <stdio.h>

void printSizeof(int arr[])
{
    printf("%d \n", (int)sizeof(arr));
}

int main(int argc, char const *argv[])
{
    int source[] = {1, 5, 3, 2, 5, 5};

    printf("%d ", (int)sizeof(source));
    printf("%d ", (int)sizeof(source[0]));
    printf("%d ", (int)sizeof(printSizeof));
    printSizeof(source);

    return 0;
}
