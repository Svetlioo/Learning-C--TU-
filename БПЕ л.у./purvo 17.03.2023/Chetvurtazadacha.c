#include <stdio.h>
int main() {
int N;
printf("Въведи число N: ");
scanf("%d", &N);
int K;
printf("Въведи число K: ");
scanf("%d", &K);
int count = 0;
for(int i = 0; i < N; i++) {
int chislo;
printf("Въведи едно от числата: ");
scanf("%d", &chislo);
if (chislo > K && chislo % 3 == 0) {
    count+= 1;
}
}
printf("The number is: %d", count);

  return 0;
}