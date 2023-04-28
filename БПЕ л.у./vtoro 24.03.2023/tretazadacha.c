#include <stdio.h>

float sum(float a,float b, float c) {
return a + b + c;
}
float biggest(float a,float b, float c) {
    if (a > b && a > c) {
        return a;
    }
    else if (b > a && b > c) {
        return b;
    }
    else {
        return c;
    }
}
float smallest(float a,float b, float c) {
    if (a < b && a < c) {
        return a;
    }
    else if (b < a && b < c) {
        return b;
    }
    else {
        return c;
    }
}

float srednoaritm(float a, float b, float c) {
    float srednoaritm = sum(a,b,c) / 3;
    return srednoaritm;
}


int main() {
    float a,b,c;
    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Enter c: ");
    scanf("%f", &c);
    printf("Chisla: %.2f, %.2f, %.2f\n", a,b,c);
    printf("Sumata: %.2f\n", sum(a,b,c));
    printf("Nai-golqmo: %.2f\n", biggest(a,b,c));
    printf("Nai-malko: %.2f\n", smallest(a,b,c));
    printf("Srednoaritm: %.2f", srednoaritm(a,b,c));
    return 0;
}