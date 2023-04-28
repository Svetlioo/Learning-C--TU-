#include <stdio.h>

int main() {
    float x1, x2, x, y;
    printf("Enter the lower bound of the interval: ");
    scanf("%f", &x1);
    printf("Enter the upper bound of the interval: ");
    scanf("%f", &x2);

    for (x = x1; x <= x2; x += 0.01) {
        y = x*x - 4;
        printf("f(%.2f) = %.2f\n", x, y);
    }

    return 0;
}
