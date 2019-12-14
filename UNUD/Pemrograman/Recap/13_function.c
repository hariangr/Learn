// Function itu cuma procedure yang mengembalikan sesuatu

#include <stdio.h>

int kaliduatambah9kurangi3(int angka) {
    int res;
    res = angka * 2 + 9 - 13;
    return res;
}

int main() {
    printf("%d\n", kaliduatambah9kurangi3(8));
    printf("%d\n", kaliduatambah9kurangi3(2));
    printf("%d\n", kaliduatambah9kurangi3(3));
    printf("%d\n", kaliduatambah9kurangi3(99));
}