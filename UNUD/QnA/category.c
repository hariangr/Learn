#include <stdio.h>
#include <string.h>

int main()
{
    float input;
    char predikat;

    printf("Input nilai input\n");
    scanf("%f", &input);

    if (input < 0 || input > 100)
    {
        printf("Input outside of boundary\n");
        return 1;
    };

    if (input >= 80)
    {
        predikat = 'A';
    }
    else if (input >= 65 && input < 80)
    {
        predikat = 'B';
    }
    else if (input >= 50 && input < 65)
    {
        predikat = 'C';
    }
    else if (input >= 40 && input < 50)
    {
        predikat = 'D';
    }
    else if (input < 40)
    {
        predikat = 'E';
    }

    printf("%c", predikat);
    printf("\n");
}
