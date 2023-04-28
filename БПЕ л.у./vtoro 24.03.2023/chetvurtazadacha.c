#include <stdio.h>
int main() {
 int x;
    printf("Enter x: ");
    scanf("%d", &x);
    if (x % 2 ==0) {
        printf("x (%d) e chetno",x);
    }
    else {
        printf("x (%d) e nechetno\n",x);
    }

    return 0;
}