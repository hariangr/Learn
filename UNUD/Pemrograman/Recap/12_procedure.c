// Procedure itu cuma function yang gak mengembalikan sesuatu, lebih mudah dijelaskan secara tatap muka

#include <stdio.h>

// Misal ada beberapa baris kode yang digunakan berulang
// Akan lebih baik memakai procedure daripada copas kode yang sama berkali-kali
// Jadi kalau mau ngubah kode, hanya perlu ngubah sekali juga yaitu di procedurenya
void printInfoOrang(char nama[100], char jenis_kelamin, int umur) {
    printf("Info dari orang\n");
    printf("> Nama adalah: %s\n", nama);
    printf("> Jenis kelamin: %c\n", jenis_kelamin);
    printf("> Umur adalah: %d\n", umur);
}

int main() {
    printInfoOrang("Sebuah nama", 'F', 11);
    printInfoOrang("Entahlah nama", 'F', 11);
    printInfoOrang("Yahya Rage Kel Nyelinap", 'F', 11);
}