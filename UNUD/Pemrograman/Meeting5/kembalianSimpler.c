#include <stdio.h>

int main()
{
    // Input harga
    int totalHarga = 0;
    for (int i = 0; 1 > 0; i++)
    {
        printf("Masukkan harga barang (Masukkan 0 untuk selesai):\n");
        int _x;
        scanf("%d", &_x);

        if (_x == 0)
        {
            break;
        }
        else
        {
            totalHarga = totalHarga + _x;
        }
    }

    // Input uang pembayaran
    printf("Masukkan pembayaran: \n");
    int _uang;
    scanf("%d", &_uang);

    // Proses kembalian
    int kembalian;
    int kelebihan;
    int num;

    kembalian = _uang - totalHarga;
    printf("Sisa kembalian: %d\n\n", kembalian);

    kelebihan = kembalian % 100000;
    num = (kembalian - kelebihan) / 100000;
    printf("100000 => %d\n", num);
    kembalian = kembalian - (num * 100000);

    kelebihan = kembalian % 50000;
    num = (kembalian - kelebihan) / 50000;
    printf("50000 => %d\n", num);
    kembalian = kembalian - (num * 50000);

    kelebihan = kembalian % 20000;
    num = (kembalian - kelebihan) / 20000;
    printf("20000 => %d\n", num);
    kembalian = kembalian - (num * 20000);

    kelebihan = kembalian % 10000;
    num = (kembalian - kelebihan) / 10000;
    printf("10000 => %d\n", num);
    kembalian = kembalian - (num * 10000);

    kelebihan = kembalian % 5000;
    num = (kembalian - kelebihan) / 5000;
    printf("5000 => %d\n", num);
    kembalian = kembalian - (num * 5000);

    kelebihan = kembalian % 2000;
    num = (kembalian - kelebihan) / 2000;
    printf("2000 => %d\n", num);
    kembalian = kembalian - (num * 2000);

    kelebihan = kembalian % 1000;
    num = (kembalian - kelebihan) / 1000;
    printf("1000 => %d\n", num);
    kembalian = kembalian - (num * 1000);

    kelebihan = kembalian % 500;
    num = (kembalian - kelebihan) / 500;
    printf("500 => %d\n", num);
    kembalian = kembalian - (num * 500);

    return 0;
}