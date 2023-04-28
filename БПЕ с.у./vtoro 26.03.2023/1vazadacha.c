#include <stdio.h> 
int main() {
    int x,y,z;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &x);
    printf("Enter z: ");
    scanf("%d", &z);
    if (x > y && x > z) {
        printf("Най-голямото число е първото и е %d", x);
    }
    else if (y > x && y > z) {
        printf("Най-голямото число е второто и е %d", y);
    }
    else {
        printf("Най-голямото число е третото и е %d", z);
    }
    

    return 0;
}