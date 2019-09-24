#include <stdio.h>

int main()
{
    float input;
    printf("Input nilai input\n");
    scanf("%f", &input);

    if (input < 0 || input > 100)
    {
        printf("Input outside of boundary\n");
        return 1;
    };

    if (input >= 80)
    {
        printf("A");
    }
    else if (input >= 65 && input < 80)
    {
        printf("B");
    }
    else if (input >= 50 && input < 65)
    {
        printf("C");
    }
    else if (input >= 40 && input < 50)
    {
        printf("D");
    }
    else if (input < 40)
    {
        printf("E");
    }

    printf("\n");
}
