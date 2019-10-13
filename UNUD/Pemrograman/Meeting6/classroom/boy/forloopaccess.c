#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("%d ", i);
    }

    printf("%d ", i);

    return 0;
}
