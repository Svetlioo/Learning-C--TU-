#include <stdio.h>
int main() {
    int x,y,z;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    printf("Before:\nx = %d, y = %d\n", x,y);
    z = x;
    x = y;
    y = z;
    printf("After:\nx = %d, y = %d", x,y);
    return 0;
}