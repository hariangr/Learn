#include <stdio.h>
#include <stdbool.h>

int arr[] = {1, 2, 3, 4, 5, 6};

bool isExist(int angka)
{
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] == angka)
        {
            return true;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
