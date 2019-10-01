#include <stdio.h>

int denominationsLength = 8;
int denominations[] = {100000, 50000, 20000, 10000, 5000, 2000, 1000, 500};

int sumPrices = 0;
int payment = 0;

void inputPrices()
{
    int n = 0;
    printf("Masukkan harga (Masukkan 0 jika tidak):\n");
    scanf("%d", &n);

    if (n == 0)
    {
        return;
    }
    else
    {
        sumPrices += n;
        inputPrices(); // Rekursif input
    }
}

void inputPayment()
{
    int _payment;
    printf("Masukkan uang pembayaran:\n");
    scanf("%d", &_payment);

    if (_payment - sumPrices < 0)
    {
        printf("Pembayaran tidak valid, ulangi\n");
        return inputPayment();
    }
    else
    {
        payment = _payment;
        printf("\n");
    }
}

void printChangeDetails()
{
    int left = payment - sumPrices;

    printf("Besar uang kembalian: %d\n", left);

    for (int i = 0; i < denominationsLength; i++)
    {
        int _over = left % denominations[i];
        int _num = (left - _over) / denominations[i];

        printf("%d => ", denominations[i]);
        printf("%d\n", _num);

        left = left - (_num * denominations[i]);
    }

    if (left > 0)
    {
        printf("Tersisa kembalian sejumlah %d\n", left);
    }
}

int main()
{
    inputPrices();

    printf("Total yang harus dibayarkan adalah %d\n\n", sumPrices);

    inputPayment();

    printChangeDetails();
}