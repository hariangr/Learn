#include <stdio.h>
int main()
{
    int hasil;
    hasil=1;

    for (int i = 5; i > 0; i = i - 1)
    {
        hasil = hasil * i;
    }

    printf("%d\n", hasil);
    
}