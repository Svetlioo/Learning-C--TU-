#include <stdio.h> 
int main() {
   int x;
    printf("Enter x: ");
    scanf("%d", &x);
    if (x % 5 == 0) {
        printf("%d", x);
    }
    else if (x % 9 == 0) {
        printf("%d", x*7);
    }
    else {
        printf("0");
    }

    return 0;
}