#include <stdio.h>
int main(){
    int angka, fungsi, variabel;
    angka=5;
    scanf ("%d", &angka);

    for (variabel=angka;variabel>=1;variabel--)
    {
        fungsi=angka-1;
        fungsi=variabel*fungsi;
    }
    printf("%d",fungsi);
return 0;
}
