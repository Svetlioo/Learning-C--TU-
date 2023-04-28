#include <stdio.h>
int main() {
    char symbol;
    printf("Enter symbol: ");
    scanf("%c", &symbol);
    int length;
    printf("Enter length: ");
    scanf("%d", &length);
    for(int i = 1; i <=length; i++) {
        for(int y = 1; y <= i; y++){
        printf("%c", symbol);
        }
    printf("\n");
    }
return 0;
}