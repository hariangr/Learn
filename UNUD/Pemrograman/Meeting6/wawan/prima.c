#include <stdio.h>

// var bisaDibagi = 0
// var input = 10

// for i in 1..input
// 	if (input % i == 0)
// 		bisaDibagi = bisaDibagi +1

// if (bisaDibagi == 2)
// 	print(“Prima”)
// else
// 	print(“Bukan prima”)

int main()
{
    int input;
    int bisadibagi = 0;
    int i;
    printf("Masukkan bilangan:");
    scanf("%d", &input);
    for (i = 1; i <= input; i++)
    {
        if (input % i == 0)
        {
            bisadibagi = bisadibagi + 1;
        }
    }
    if (bisadibagi == 2)
    {
        printf("bilangan prima");
    }
    else
    {
        printf("bukan bilangan prima");
    }
    return 0;
}