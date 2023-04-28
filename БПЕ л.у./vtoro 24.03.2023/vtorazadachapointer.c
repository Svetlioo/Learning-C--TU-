#include <stdio.h>
int subirane(int* pointer1, int* pointer2) {
return *pointer1 + *pointer2;
}

int izvajdane(int* pointer1, int* pointer2) {
return *pointer1 - *pointer2;
}

int umnojenie(int* pointer1, int* pointer2) {
return *pointer1 * *pointer2;
}

float delenie(int* pointer1, int* pointer2) {
return (float)*pointer1 / (float)*pointer2;
}


int main() {
    int x, y;
    int* px = &x;
    int* py = &y;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    printf("x = %d,y = %d\n", x, y);
    printf("Sumata = %d\n", subirane(px, py));
    printf("Razlika = %d\n",izvajdane(px, py));
    printf("Umnojenie = %d\n",umnojenie(px, py));
    printf("Delenie = %.2f\n", delenie(px,py));

    return 0;
}