#include <stdio.h>
int main() {

int chislo;
printf("Въведи число: ");
scanf("%d", &chislo);
for(int i = 1; i <= chislo; i++) {
    for(int x = 1; x <= i; x++) {
        printf("%d", i);
    }
    printf("\n");
}

  return 0;
}