// Misal sebuah teks prosedur
//
// 1. Buat variabel x
// 2. Isi x dengan nilai awal 0
// 3. Print nilai x ke layar
// 4. Tambahkan nilai x dengan nilai x sebelumnya + 1
// 5. Ulangi langkah 3-5 selama nilai x lebih kecil dari 10

#include <stdio.h>

int main()
{
    int x;
    x = 0;

    while (x < 10)
    {
        printf("%d\n", x);
        x = x + 1;
    }
}