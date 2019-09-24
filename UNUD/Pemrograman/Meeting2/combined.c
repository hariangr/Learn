#include <stdio.h>
#include <string.h>

char * rate(float _input)
{
    if (_input >= 80)
    {
        return "A";
    }
    else if (_input >= 65 && _input < 80)
    {
        return "B";
    }
    else if (_input >= 50 && _input < 65)
    {
        return "C";
    }
    else if (_input >= 40 && _input < 50)
    {
        return "D";
    }
    else if (_input < 40)
    {
        return "E";
    }
}

int main()
{
    int a, b, c;
    float _a, _b, _c;
    float res;

    printf("Masukkan 3 nilai dibatasi spasi\n");
    scanf("%d %d %d", &a, &b, &c);

    _a = (float)a;
    _b = (float)b;
    _c = (float)c;

    res = (_a + _b + _c) / 3.0;
    

    printf("%f", res);
}
