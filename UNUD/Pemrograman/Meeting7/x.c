#include <stdio.h>

void recurf(int input, int saat_ini)
{
    if (saat_ini == 0)
        return;

    printf("%d ", saat_ini);
    recurf(input, saat_ini - 1);
}

int main(int argc, char const *argv[])
{
    recurf(5, 5);
    return 0;
}
