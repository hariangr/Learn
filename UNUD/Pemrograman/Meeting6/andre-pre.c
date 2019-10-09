#include <stdio.h>
#include <stdlib.h>

int main()
{
int a,b;
int P1,L1,P2,L2,L3;                         //menyimpan pangjang dan lebar
    printf("masukkan panjang matrix 1 'a'x'b' : \n");
    scanf ("%d %d",&a,&b);
    P1=a;
    L1=b;
    int Matrix1[a][b];
    printf("masukkan panjang matrix 2 'a'x'b' : \n");
    scanf ("%d %d",&a,&b);
    P2=a;
    L2=b;
    int Matrix2[a][b];
    if( L1!=P2)
        {
        printf("Tidak Bisa dikalikan");
        }
    else
        {                       //Membuat Matrix hasil
//        P3=P1;
        L3=P1;
        int Matrix3[10][10];
        int i=1,j=1;                        //menghitung baris dan kolom ke =
        for(a=0;a<=P1-1;a++)
            {               //menginput Semua nilai matrix 2d
            for(b=0;b<=L1-1;b++)
                {
                printf("masukkan nilai matrix1 row ke %d Kolom ke %d = ",a+1,b+1);
                j++;
                scanf("%d",&Matrix1[a][b]);
                }
            i++;
            j=1;
            }
        for(a=0;a<P1;a++)
            {                      //Print Preview Matrix 1
                printf("{");
            for(b=0;b<L1;b++)
                {
                printf(" %d ",Matrix1[a][b]);
                }
            printf("}\n");
            }
        i=1;
        j=1;
        for(a=0;a<=P2-1;a++)
            {                   //Menghitung Baris dan kolom matrix 2
            for(b=0;b<=L2-1;b++)
                {
                printf("masukkan nilai matrix2 row ke %d Kolom ke %d = ",i,j);
                j++;
                scanf("%d",&Matrix2[a][b]);
                }
            i++;
            j=1;
            }
        for(a=0;a<P2;a++)
            {                      //Print Preview matrix 2
                printf("{");
            for(b=0;b<L2;b++)
                {
                printf(" %d ",Matrix2[a][b]);
                }
            printf("}\n");
            }
        int c,e=0;                                                        //Mengisi nilai matrix hasil
        printf("\n\nMatrix Hasil Adalah :\n");
        for(a=0;a<L3;a++)
            {
                printf("{");
            for(b=0;b<=L2-1;b++)
                {
                for(c=0;c<P2;c++)
                    {
                    e=e+Matrix1[a][c]*Matrix2[c][b];
//                  printf("%da %db %dc %de\n",a,b,c,e);         //Cek nilai
                    }
//                  printf("%da %db\n",a,b);                             //Cek Nilai
                    Matrix3[a][b]=e;
                    e=0;
                    printf(" %d ",Matrix3[a][b]);
                }
            printf("}\n");
            }
        }
    return 0;
}