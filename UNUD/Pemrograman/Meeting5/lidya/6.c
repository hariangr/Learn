#include <stdio.h>
int main()
{
    int hasil;
    hasil = 1;
    int input;
    
    printf("masukan bilangan bulat\n");
    scanf("%d", &input);

    for (int i = input; i > 0; i = i - 1)
    {
        hasil = hasil * i;
    }

    printf("%d\n", hasil);
}