#include <stdio.h>

double funkciq (double* pointer1,double* pointer2,int* pointer3) {
}




int main() {
    double r;
    int* pr = &r;
    printf("Enter r: ");
    scanf("%lf", &r);
    double duljnite = 3.14 * *pr;
    double lice = 3.14 * (*pr) * (*pr);

    return 0;
}