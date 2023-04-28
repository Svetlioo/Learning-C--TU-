#include <stdio.h>
int main() {

float chislo1, chislo2, chislo3;
printf("Enter number 1: ");
scanf("%f", &chislo1);
printf("Enter number 2: ");
scanf("%f", &chislo2);
printf("Enter number 3: ");
scanf("%f", &chislo3);

if (chislo3 < chislo2 && chislo3<chislo1) {
    printf("Числото %.2f е най-малко", chislo3);
}
else if (chislo2 < chislo1) {
    printf("Числото %.2f е най-малко", chislo2);
}
else {
 printf("Числото %.2f е най-малко", chislo1);
}
  return 0;
}
