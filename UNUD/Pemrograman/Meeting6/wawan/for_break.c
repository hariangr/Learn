#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", i);

        if (i == 7)
        {
            break;
        }
    }

    return 0;
}
