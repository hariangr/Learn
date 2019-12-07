#include <stdio.h>

void printMatrix(int *arr[], int len) {
    for (int i = 0; i< len; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    int a[] = {1,2,3,4};
    printMatrix(&a, 4);

    return 0;
}