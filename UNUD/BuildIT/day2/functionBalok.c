#include <stdio.h>

int calculateVolume(int width, int height, int depth)
{
    return width * height * depth;
}

int main(int argc, char const *argv[])
{
    int w, h, d;
    printf("Masukkan lebar tinggi dan panjang dipisahkan spasi:\n");
    scanf("%d %d %d", &w, &h, &d);

    int volumeBalok = calculateVolume(w, h, d);
    printf("%d\n", volumeBalok);

    return 0;
}
