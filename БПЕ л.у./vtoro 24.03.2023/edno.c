#include <stdio.h>


int bigger(int x,int y) {
    (x > y) ? printf("x (%d) is bigger than y (%d).", x,y) : printf("y (%d) is bigger than x (%d).", y, x);
    return 0;
}

int main() {
    int x,y;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    bigger(x,y);
    return 0;
}