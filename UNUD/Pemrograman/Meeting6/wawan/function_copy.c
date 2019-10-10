#include <stdio.h>

void printLetter(int a)
{
    if (a == 1)
    {
        printf("A\n");
    }
    else if (a == 2)
    {
        printf("B\n");
    }
    else if (a == 3)
    {
        printf("C\n");
    }
    else if (a == 4)
    {
        printf("D\n");
    }
    else
    {
        printf("error\n");
    }
}

void printOddEven(int a)
{
    char wordOdd[20] = "GANJIL";
    char wordEven[20] = "Genap";

    if (a % 2 == 0)
    {
        printf("%s", wordEven);
    }
    else
    {
        printf("%s", wordOdd);
    }
}

void suatuprint(int a)
{
    printLetter(a);
    printOddEven(a);
}

int main(int argc, char const *argv[])
{
    suatuprint(3);

    printf("\n");
    return 0;
}
