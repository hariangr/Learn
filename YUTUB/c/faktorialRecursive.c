// 5! = 5 x 4 x 3 x 2 x 1 = 120
#include <stdio.h>

int recurf(int cur, int sum)
{
    printf(" %d ", cur);

    if (cur == 1)
    {
        return sum;
    }
    else if (cur > 1)
    {
        printf("x");
        return recurf(cur - 1, sum * cur);
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int input;
    printf("Masukkan sebuah bilangan bulat?\n");
    scanf("%d", &input);

    printf("%d! =", input);
    int res = recurf(input, 1);

    printf("= %d\n", res);

    return 0;
}
