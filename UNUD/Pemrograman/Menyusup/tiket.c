#include <stdio.h>
#include <stdbool.h>

int cur = 0;
int ordered[20];

bool isOrdered(int kursi)
{
    bool _o = false;

    for (int i = 0; i < cur; i++)
    {
        if (ordered[i] == kursi)
        {
            return true;
        }
    }

    return false;
}

void printAvailable()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int offset = i * 5;

            if (isOrdered(offset + j) == false)
            {
                printf("[%2d]\t", offset + j);
            }
            else
            {
                printf("____\t");
            }
        }

        printf("\n");
    }
}

void reserveOne()
{
    printf("Pilih kursi ");
    int i;
    scanf("%d", &i);
    ordered[cur] = i;
    cur++;
}

int main()
{
    while (true)
    {
        printAvailable();
        reserveOne();
    }
}
