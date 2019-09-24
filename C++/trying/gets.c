#include <stdio.h>

int main() {
    char nama[40];
    int tahun;
    
    printf("Program mengukur umur\n\n");
    
    printf("Masukkan nama anda?");
    gets(nama);
    
    printf("Masukkan tanggal lahir?");
    scanf("%d", &tahun);
    
    printf("Umur anda adalah %d tahun", 2019-tahun);
    
    return 0;
}