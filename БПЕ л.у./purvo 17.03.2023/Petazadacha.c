#include <stdio.h>
int main() {
    float sum;
    while (1) {
        float chislo;
        printf("Enter number: ");
        scanf("%f", &chislo);
        if (chislo!=0) {
        sum+=chislo;
        }
        else {
            printf("%.2f", sum);
            return 0;
        }
    }
}