#include <stdio.h>
#include <stdlib.h>

int main() {
    char x[5] = "-143";
    printf("%s\n", x);

    int y = atoi(x);
    y++;
    printf("%d\n", y);
}