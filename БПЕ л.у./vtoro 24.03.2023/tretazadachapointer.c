#include <stdio.h>

int addTwo(int* pointer) {
    return *pointer + 2;
}


int main() {
    int x;
    int* px = &x;
    printf("Enter x: ");
    scanf("%d", &x);
    int novaStoinost = addTwo(px);
    printf("%d\n", novaStoinost);

    return 0;
}