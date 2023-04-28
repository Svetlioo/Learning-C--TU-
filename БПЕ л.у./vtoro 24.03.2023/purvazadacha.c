#include <stdio.h>

int kvadrat(int a) {
    return (a*a);
}
int pravougulnik(int a, int b) {
    return (a*b);
}
int pravougtriug(int a,int b) {
    return (a*b) / 2;
}
float krug(float r) {
    return (r*r*3.14);
}




int main() {
int choice;
printf("Enter 1,2,3 or 4: ");
scanf("%d", &choice);

switch (choice) {
    case 1: {
        int a;
        printf("Enter a: ");
        scanf("%d", &a);
        printf("S na kvadrat = %d", kvadrat(a));
        break;
    }
    case 2: {
        int a,b;
        printf("Enter a: ");
        scanf("%d", &a);
        printf("Enter b: ");
        scanf("%d", &b);
        printf("S na pravougulnik = %d", pravougulnik(a,b));
        break;
    }
    case 3: {
        int a,b;
        printf("Enter a: ");
        scanf("%d", &a);
        printf("Enter b: ");
        scanf("%d", &b);
        printf("S na pravougulen triugulnik = %d", pravougtriug(a,b));
        break;
    }
    case 4: {
        int r;
        printf("Enter r: ");
        scanf("%d", &r);
        printf("S na kvadrat = %f", krug(r));
        break;
    }
    default: printf("Enter valid number.");
}

    return 0;
}