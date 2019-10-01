#include <stdio.h>
#include <stdbool.h>

int n = 5;
bool isPrime(int input)
{
    if (input <= 3)
    {
        // 2 dan 3
        return input > 1;
    }
    else if (input % 2 == 0 || input % 3 == 0)
    {
        // If it is divisible by 2 or 3, it isn't prime
        return false;
    }
    else
    {
        int i = 5;
        while (i * i <= input)
        {
            if (input % i == 0 || input % (i + 2) == 0)
            {
                return false;
            }

            i = i + 6;
        }

        return true;
    }
}

int main()
{
    printf("Masukkan sebuah bilangan bulat: \n");
    scanf("%d", &n);

    if (isPrime(n))
    {
        printf("%d adalah bilangan prima\n", n);
    }
    else
    {
        printf("%d bukan bilangan prima\n", n);
    }
}