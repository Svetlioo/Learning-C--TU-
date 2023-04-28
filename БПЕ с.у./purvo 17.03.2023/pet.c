#include <stdio.h>
#include <math.h>
int main() {
    float x1,x2,x3,y1,y2,y3;
    printf("Enter x1: ");
    scanf("%f", &x1);
    printf("Enter x2: ");
    scanf("%f", &x2);
    printf("Enter x3: ");
    scanf("%f", &x3);
    printf("Enter y1: ");
    scanf("%f", &y1);
    printf("Enter y2: ");
    scanf("%f", &y2);
    printf("Enter y3: ");
    scanf("%f", &y3);
    
    float a = fabs(x3 - x1);
    float h = fabs(y3 - y1);
    float S = (a*h) / 2;
    printf("%.2f", S);
return 0;
}