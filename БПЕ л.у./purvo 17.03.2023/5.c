#include <stdio.h>
int main() {

int chislo;
printf("Enter number: ");
scanf("%d", &chislo);

int sum = 0;
int count = 0;
while(chislo>0) {
    sum+= chislo % 10; //int = 381
    chislo= chislo/10;
    count++;
}
if(chislo/count > 5) {
    printf("po golqmo\n");
}
if(chislo/count < 5) {
    printf("po malko\n");
}

printf("%d", sum);
  return 0;
}
