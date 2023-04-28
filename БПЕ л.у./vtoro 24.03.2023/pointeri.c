#include <stdio.h>
int main() {
    int x = 14;
    int *p = &x;
    printf("x = %d,\nx value = %d,\nx memory = %p \n",x , *p, p);
    printf("Memory of pointer: %p\n", &p);
    printf("%p", &x);

    return 0;
}