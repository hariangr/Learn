#include <stdio.h>
#include <stddef.h>

int main(int argc, char const *argv[])
{
    int length = 9;
    int source[] = {6, 5, 4, 2, 1, 7, 8, 9, 0};

    int lookFor = 7;
    int foundAt = -1;

    for (int i = 0; i < length; i++)
    {
        if (source[i] == lookFor)
        {
            foundAt = i;
            break;
        }
    }

    printf("Nilai %d ditemukan di index %d\n", lookFor, foundAt);

    return 0;
}
