#include <stdio.h>

void suatuprint(int a)
{
    char wordOdd[20] = "GANJIL";
    char wordEven[20] = "Genap";

    if (a == 1)
    {
        printf("A\n");
        printf("%s", wordOdd);
    }
    else if (a == 2)
    {
        printf("B\n");
        printf("%s", wordEven);
    }
    else if (a == 3)
    {
        printf("C\n");
        printf("%s", wordOdd);
    }
    else if (a == 4)
    {
        printf("D\n");
        printf("%s", wordEven);
    }
    else
    {
        printf("error");
        if (a % 2 == 0)
        {
            printf("\n%s", wordEven);
        }

        else
        {
            printf("\n%s",wordOdd);
        }
    }
}

int main(int argc, char const *argv[])
{
    suatuprint(3);

    printf("\n");
    return 0;
}
