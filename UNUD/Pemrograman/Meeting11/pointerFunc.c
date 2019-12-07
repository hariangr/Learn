#include <stdio.h>

// void printer(int *toPrint) {
//     printf("%d\n", toPrint);
//     printf("%d\n", &toPrint);
// }

int main() {
    int arr[2][3] = {{1,2,5}, {3,4,6}};
    int *arrPtr = &arr;

    for (int i = 0; i<4; i++) {
        printf("%d\n", *arrPtr);
        arrPtr++;
    }

    return 0;
}
