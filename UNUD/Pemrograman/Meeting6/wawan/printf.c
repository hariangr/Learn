#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("tulisan");
    printf("tulisan\n");
    printf("%d", 4);

    int a = 10;
    printf("%d", a);

    printf("tulisan %d", a);

    printf("tulisan %d\n", a);
    printf("tulisan %d\n\n\n", a);

    printf("%d %d", 1, 2);
    
    char z[10] = "NAMA";
    printf("%s", z);


    char y[10]= "NIM";
    printf ("%s %s",y,y);

    printf ("%d       ",a);
    printf("%s",y);

    printf("%d    %s",a,y);

    printf("%d   %s:%d",a,y,24);

    printf("%d\t%s:%d",a,y,24);


    return 0;
}
