#include <stdio.h>

int arr[] = {1, 2, 3, 4, 5, 8, 12, 58, 99};

int counter = 0;

/// Look for index
///
/// -1 mean not found
int getIndex(int lookFor, int lower, int upper)
{
    counter++;
    if (counter == 25)
        return -1;

    int _mid = (upper + lower) / 2;
    printf("Iteration no. %d\tlookFor %d, lower %d, upper %d, mid %d\n", counter, lookFor, lower, upper, _mid);

    if (upper == lower || lower == _mid)
        return -1;

    if (arr[_mid] == lookFor)
    {
        return _mid;
    }
    else if (arr[upper] == lookFor)
    {
        return upper;
    }
    else if (arr[lower] == lookFor)
    {
        return lower;
    }

    if (arr[_mid] > lookFor)
    {
        // Look left
        return getIndex(lookFor, lower, upper / 2);
    }
    else if (arr[_mid] < lookFor)
    {
        // Look right
        return getIndex(lookFor, _mid, upper);
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    /* code */
    int temu = getIndex(4, 0, 8);
    printf("%d\n", temu);

    return 0;
}
