#include <stdio.h>

char karakter[5] = {'a', 'b', 'c', 'd'};
int length = 4;
int openHead = 2;
int closeHead = 0;

char getAt(int pos)
{
    int _current = openHead;
    int _curI = 0;

    if (openHead == 0)
    {
        return karakter[pos];
    }

    if (pos >= length)
    {
        printf("ERROR");
        return NULL;
    }

    while (1 > 0)
    {
        if (_current == closeHead + 1)
        {
            _current = openHead;
            _curI++;
        }

        if (_curI == pos)
            return karakter[_current];

        _current++;
        _curI++;
    }
}

int main()
{

    for (int i = 0; i < 5; i++)
    {
        printf("%c", karakter[i]);
    }

    printf("\n");

    printf("%c", getAt(2));

    printf("\n");

    for (int a = 0; a < length; a++)
    {
        printf("%c", getAt(a));
    }

    return 0;
}