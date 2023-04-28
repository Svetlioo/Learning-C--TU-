#include <stdio.h>
int main() {
    int x = 14;
    int *p = &x;
    printf("x = %d,\nValue of x = %d,\nMemory of x = %p \n",x , *p, p);
    printf("Memory of pointer: %p\n", &p);
    printf("Memory of x = %p", &x);

    return 0;
}