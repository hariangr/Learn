#include <stdio.h>
#include <stdbool.h>

int n = 5;
int main()
{
    printf("Masukkan sebuah bilangan bulat: \n");
    scanf("%d", &n);

    bool isEven = n % 2 == 0;

    printf("Nilai yang dimasukkan adalah bilangan ");

    if (isEven)
    {
        printf("genap");
    }
    else
    {
        printf("ganjil");
    }

    printf("\n");
    return 0;
}