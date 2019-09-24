#include <stdio.h>

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
