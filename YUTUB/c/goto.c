#include <stdio.h>

int main(int argc, char const *argv[])
{

    int i = 0;

increase:
    printf("%d\n", i);
    i++;

    if (i == 5000)
        goto out;

    goto increase;

out:
    printf("Finish");

    return 0;
}
