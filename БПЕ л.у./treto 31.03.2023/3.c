#include <stdio.h>

int main() {
    int a[2] = {3, 21};
    int* pointer = &a;
    for (int i = 0; i < 2; i++) {
        printf("%d", *pointer);
    }



    return 0;
}