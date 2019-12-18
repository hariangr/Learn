#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();
int option1();
int option2();
int option3();
int option4();
void swap(char *s1,int *a1,int *b1,int *c1,int *d1,int *e1,int *f1,char *s2,int *a2,int *b2,int *c2,int *d2,int *e2,int *f2);//struct is a lot better tpi blm terlalu ngerti
int main()
{
    menu();
    return 0;
}

int menu(){
    int pilihan,counter=1;
    while(counter<100){         //kondisi break hanya saat counter 100+ dan counter hanya ditambah di case 0 (infinite loop)
        printf("\n\npilih menu :\n1.menambahkan data\n2.melihat isi data\n3.import file\n4.export file\n0.Exit\n\nNUMBERS ONLY\n\n\n==========");
        scanf("%d",&pilihan);
        switch(pilihan){
            case 1 :
                option1();
                break;
            case 2 :
                option2();
                break;
            case 3 :
                option3();
                break;
            case 4 :
                option4();
                break;
            case 0 :
                counter+= 100;
                break;
            default :
                printf("option is not available");
                break;
        }
    }
    return 0;
}

int option1(){
    char def[50];                                   //def for file specifier
    char sex;                                       //data stored harusnya struct
    int age,studytime,absences,G1,G2,G3;
    int zed;                                        //zed untuk memilih isi def
    printf("1.default (D:\\Andre\\Tugas word\\masters.txt)\n2.custom path\n==========");
    scanf("%d",&zed);
    switch(zed){
        case 1:
            strcpy(def, "D:\\Andre\\Tugas word\\masters.txt");
            break;
        case 2:
            scanf("\n%[^\n]s",def);
            break;
        default :
            printf("[option is not available, continueing with default settings]\n");
    }
    FILE *ptrnew = fopen(def,"a");
    if(ptrnew == NULL) {
		printf("error\n");
		return 1;
	}
	int input = 1;                                  //perulangan loop untuk menambah data
	while(input == 1){
        printf("input sex,age,studytime,absences,G1,G2,G3\n");
        scanf(" %c %d %d %d %d %d %d",&sex,&age,&studytime,&absences,&G1,&G2,&G3);
        fprintf(ptrnew,"%c %d %d %d %d %d %d\n",sex,age,studytime,absences,G1,G2,G3);
        printf("then add another ? (1/0) \n");
        scanf("%d",&input);
        while(input != 1 && input != 0){
            printf("wrong input !\n");
            scanf("%d",&input);
            }
    }
	fclose(ptrnew);
    return 1;
}

int option2(){
    char def[50];
    char tester[100],**tocopy = NULL;                                       //def for file specifier    |   tester for temp text holder for --->  |   tocopy for text holder
    char sex[100];                                                                  //data stored harusnya struct
    int age[100],studytime[100],absences[100],G1[100],G2[100],G3[100];
    int zed,linenum = 0;                                                            //Counter and input only only
    int x,y;                                                                       //int for bubblesort
    printf("1.default (D:\\Andre\\Tugas word\\masters.txt)\n2.custom path\n==========");
    scanf("%d",&zed);
    switch(zed){
        case 1:
            strcpy(def, "D:\\Andre\\Tugas word\\masters.txt");
            break;
        case 2:
            scanf("\n%[^\n]s",def);
            break;
        default :
            printf("[option is not available, continueing with default settings]\n");
    }
    FILE *ptrnew = fopen("D:\\Andre\\Tugas word\\master.txt","a");
    if(ptrnew == NULL) {
		printf("error\n");
		return 1;
	}
	int pilihan,i=0;
	printf("pilih isi yang mau dilihat :\n1.semua isi text\n2.male only\n3.female only\n4.menurut skor G3\n0.kembali\n==========");
	scanf("%d",&pilihan);
	switch(pilihan){
        case 1:
            printf("\n-------------------------\n");
            /*Old alternative code
                hanya bisa menampilkan data yg sesuai format dan error saat hanya string spt line 1 pada file master.txt
                case 1 menampilkan semua isi file txt*/
//            while(!feof(ptrnew)){
//            fscanf(ptrnew," %c %d %d %d %d %d %d\n",&sex[i],&age[i],&studytime[i],&absences[i],&G1[i],&G2[i],&G3[i]);
//            printf(" %c %d %d %d %d %d %d\n",sex[i],age[i],studytime[i],absences[i],G1[i],G2[i],G3[i]);
//            i++;
//            }//
            // source code https://stackoverflow.com/questions/28536150/how-to-sort-data-inside-txt-files-in-c/28537858
            while(fgets(tester, 100, ptrnew) != NULL){
                if(strchr(tester,'\n')){
                    tester[strlen(tester)-1] = '\0';
                    tocopy = (char**)realloc(tocopy, sizeof(char**)*(linenum+1));
                    tocopy[linenum] = (char*)calloc(100,sizeof(char));
                    strcpy(tocopy[linenum], tester);
                    linenum++;
                }
            }
            for(i = 0; i < linenum; i++)printf("%s\n",tocopy[i]);
            for(i = 0; i < linenum; i++)free(tocopy[i]);
            free(tocopy);
            printf("-------------------------\n");
            fclose(ptrnew);
            break;
        case 2:
            printf("\n---------------\n");
            while(!feof(ptrnew)){
            fscanf(ptrnew," %c %d %d %d %d %d %d\n",&sex[i],&age[i],&studytime[i],&absences[i],&G1[i],&G2[i],&G3[i]);
            if(sex[i] == 'm' || sex[i] == 'M')printf(" %c %d %d %d %d %d %d\n",sex[i],age[i],studytime[i],absences[i],G1[i],G2[i],G3[i]);
            i++;
            }
            printf("---------------\n");
            break;
        case 3:
            while(!feof(ptrnew)){
                fscanf(ptrnew,"%c %d %d %d %d %d %d",&sex[i],&age[i],&studytime[i],&absences[i],&G1[i],&G2[i],&G3[i]);
                if(sex[i] == 'f'||sex[i] == 'F')printf(" %c %d %d %d %d %d %d\n",sex[i],age[i],studytime[i],absences[i],G1[i],G2[i],G3[i]);
                i++;
            }
            break;
        case 4:
            printf("\n---------------\n");
            while(!feof(ptrnew)){
            fscanf(ptrnew," %c %d %d %d %d %d %d\n",&sex[i],&age[i],&studytime[i],&absences[i],&G1[i],&G2[i],&G3[i]);
            i++;
            }
            for (x = 0; x < i-1; x++)
                for (y = 0; y < i-x-1; y++)
                    if (G3[y] > G3[y+1])swap(&sex[y],&age[y],&studytime[y],&absences[y],&G1[y],&G2[y],&G3[y],&sex[y+1],&age[y+1],&studytime[y+1],&absences[y+1],&G1[y+1],&G2[y+1],&G3[y+1]);
            while(i>0){
                printf(" %c %d %d %d %d %d %d\n",sex[i-1],age[i-1],studytime[i-1],absences[i-1],G1[i-1],G2[i-1],G3[i-1]);
                i--;
            }
            printf("---------------\n");
            fclose(ptrnew);
            break;
        case 0:
            break;
	}
	return 1;
}

int option3(){
    char dari[50],ke[50];                                                           //dari directory asal file  |   ke directory tujuan
    char sex[200];                                                                  //data stored harusnya struct
    int age[200],studytime[200],absences[200],G1[200],G2[200],G3[200];
    printf("darimana file akan di import ?\n");
    scanf("\n%[^\n]s",dari);
    FILE *ptrnew = fopen(dari,"r");
    if(ptrnew == NULL) {
        printf("error/file tidak ditemukan\n");
        return 1;
	}
	int i=0;
    printf("---------------\n");
    while(!feof(ptrnew)){
        fscanf(ptrnew," %c %d %d %d %d %d %d\n",&sex[i],&age[i],&studytime[i],&absences[i],&G1[i],&G2[i],&G3[i]);
        printf(" %c %d %d %d %d %d %d\n",sex[i],age[i],studytime[i],absences[i],G1[i],G2[i],G3[i]);
        i++;
    }
    printf("---------------\n\n\tpreview file yang imgin di import");
    fclose(ptrnew);
    printf("kemana file akan di export ?\n");
    scanf("\n%[^\n]s",ke);
    FILE *ptradd = fopen(ke,"a");
    int n=0;
    while(n<i){
            fprintf(ptradd," %c %d %d %d %d %d %d\n",sex[n],age[n],studytime[n],absences[n],G1[n],G2[n],G3[n]);
            n++;
            }
    printf("Content has been successfully copied\n");
    fclose(ptradd);
    return 0;
}

int option4(){
    char sex[100],tester[100],dari[50],ke[50];
    char **tocopy = NULL;
    int age[100],studytime[100],absences[100],G1[100],G2[100],G3[100],mean[100],meankls=0;
    int linenum = 0;                                                           //Counter only
    int x, y;
    printf("darimana file akan di export (directory ex [D:\\Andre\\Tugas word\\filename.txt] or filename.txt)?\n");
    scanf("\n%[^\n]s",dari);
    FILE *ptrnew = fopen(dari,"r");
    if(ptrnew == NULL) {
        printf("error/file tidak ditemukan\n");
        return 1;
	}

    printf("kemana file akan di export (directory ex [D:\\Andre\\Tugas word\\filename.txt] or filename.txt)\n");
    scanf("\n%[^\n]s",ke);
    FILE *ptradd = fopen(ke,"w");

	int pilihan=5,i=0;
	printf("pilih option untuk export :\n1.semua isi file\n2.male only\n3.female only\n4.menurut skor G3\n5.nilai diatas rata - rata(no files yet)\n0.kembali\n==========");
	scanf("%d",&x);
	switch(pilihan){
        case 1:
            while(fgets(tester, 100, ptrnew) != NULL){
                if(strchr(tester,'\n')){
                    tester[strlen(tester)-1] = '\0';
                    tocopy = (char**)realloc(tocopy, sizeof(char**)*(linenum+1));
                    tocopy[linenum] = (char*)calloc(100,sizeof(char));
                    strcpy(tocopy[linenum], tester);
                    linenum++;
                }
            }
            for(i = 0; i < linenum; i++)fprintf(ptradd,"%s\n",tocopy[i]);
            for(i = 0; i < linenum; i++)free(tocopy[i]);
            free(tocopy);
            fclose(ptrnew);
            fclose(ptradd);
            break;
        case 2:
            while(!feof(ptrnew)){
            fscanf(ptrnew," %c %d %d %d %d %d %d\n",&sex[i],&age[i],&studytime[i],&absences[i],&G1[i],&G2[i],&G3[i]);
            if(sex[i] == 'm' || sex[i] == 'M')fprintf(ptradd," %c %d %d %d %d %d %d\n",sex[i],age[i],studytime[i],absences[i],G1[i],G2[i],G3[i]);
            i++;
            }
            fclose(ptrnew);
            fclose(ptradd);
            break;
        case 3:
            while(!feof(ptrnew)){
            fscanf(ptrnew," %c %d %d %d %d %d %d\n",&sex[i],&age[i],&studytime[i],&absences[i],&G1[i],&G2[i],&G3[i]);
            if(sex[i] == 'f' || sex[i] == 'F')fprintf(ptradd," %c %d %d %d %d %d %d\n",sex[i],age[i],studytime[i],absences[i],G1[i],G2[i],G3[i]);
            i++;
            }
            fclose(ptrnew);
            fclose(ptradd);
            break;
        case 4:
            while(!feof(ptrnew)){
            fscanf(ptrnew," %c %d %d %d %d %d %d\n",&sex[i],&age[i],&studytime[i],&absences[i],&G1[i],&G2[i],&G3[i]);
            i++;
            }
            for (x = 0; x < i-1; x++)
                for (y = 0; y < i-x-1; y++)
                    if (G3[y] > G3[y+1])swap(&sex[y],&age[y],&studytime[y],&absences[y],&G1[y],&G2[y],&G3[y],&sex[y+1],&age[y+1],&studytime[y+1],&absences[y+1],&G1[y+1],&G2[y+1],&G3[y+1]);
            while(i>0){
                printf(" %c %d %d %d %d %d %d\n",sex[i-1],age[i-1],studytime[i-1],absences[i-1],G1[i-1],G2[i-1],G3[i-1]);
                fprintf(ptradd," %c %d %d %d %d %d %d\n",sex[i-1],age[i-1],studytime[i-1],absences[i-1],G1[i-1],G2[i-1],G3[i-1]);
                i--;
            }
            fclose(ptrnew);
            fclose(ptradd);
            break;
        case 5:
            while(!feof(ptrnew)){
            fscanf(ptrnew," %c %d %d %d %d %d %d\n",&sex[i],&age[i],&studytime[i],&absences[i],&G1[i],&G2[i],&G3[i]);
            mean[i] = G1[i]+G2[i]+G3[i];
            meankls += mean[i];
            i++;
            }
            meankls=meankls/i;
            for (x = 0; x < i-1; x++)
                for (y = 0; y < i-x-1; y++){
                    if (mean[y] > mean[y+1])swap(&sex[y],&age[y],&studytime[y],&absences[y],&G1[y],&G2[y],&G3[y],&sex[y+1],&age[y+1],&studytime[y+1],&absences[y+1],&G1[y+1],&G2[y+1],&G3[y+1]);
                    mean[y]+=mean[y+1],mean[y+1]=mean[y]-mean[y+1];
                    mean[y]-=mean[y+1];
                }
            while(i>0){
                if(mean[i]>meankls){
                printf(" %c %d %d %d %d %d %d\n",sex[i-1],age[i-1],studytime[i-1],absences[i-1],G1[i-1],G2[i-1],G3[i-1]);
                fprintf(ptradd," %c %d %d %d %d %d %d\n",sex[i-1],age[i-1],studytime[i-1],absences[i-1],G1[i-1],G2[i-1],G3[i-1]);
                }
                i--;
            }
            fclose(ptrnew);
            fclose(ptradd);
        case 0:
            break;
    }
	return 1;
}


void swap(char *s1,int *a1,int *b1,int *c1,int *d1,int *e1,int *f1,char *s2,int *a2,int *b2,int *c2,int *d2,int *e2,int *f2){
    char s3=*s1;
    int a3=*a1,b3=*b1,c3=*c1,d3=*d1,e3=*e1,f3=*f1;
    *s1=*s2;
    *a1=*a2,*b1=*b2,*c1=*c2,*d1=*d2,*e1=*e2,*f1=*f2;
    *s2=s3;
    *a2=a3,*b2=b3,*c2=c3,*d2=d3,*e2=e3,*f2=f3;
}
