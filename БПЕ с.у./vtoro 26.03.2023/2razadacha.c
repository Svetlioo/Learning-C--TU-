#include <stdio.h> 
int main() {
    int x,y;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    int bigger;
    if (x > y) {
        bigger = x;
        printf("Числото %d е по-голямо.",bigger);
    }
    else if (y > x) {
        bigger = y;
         printf("Числото %d е по-голямо.",bigger);
    }
    else {
        printf("Числата са равни.");
    }

    return 0;
}