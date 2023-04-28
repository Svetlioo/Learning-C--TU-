#include <stdio.h>
int main() {

int chislo;
printf("Въведи число: ");
scanf("%d", &chislo);
if((chislo % 8) < 4) {
  printf("%d", chislo % 8);
}

  return 0;
}