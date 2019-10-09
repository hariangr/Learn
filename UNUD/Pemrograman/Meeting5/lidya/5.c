#include <stdio.h>

int main()
{
    int n;

    printf("masukkan bilangan?\n");
    scanf("%d", &n);

    if (n % 2 == 1)
    {
        printf("nilai yang dimasukkan adalah bilangan ganjil\n");
    }

    if (n % 2 == 0)
    {
        printf("nilai yang dimasukkan adalah bilangan genap\n");
    }
}
