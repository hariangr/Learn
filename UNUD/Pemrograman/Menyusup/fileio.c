#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *open = fopen("namafile.txt", "r");

    while (!feof(open))
    {
        char buff1[255];
        char buff2[255];

        fscanf(open, "%[^#]#%[^#]\n", &buff1, &buff2);
        fflush(open);
        printf("%s\n", buff1);
    }

    /* code */
    return 0;
}
