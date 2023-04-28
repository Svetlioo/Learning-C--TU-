#include <stdio.h>
int main(){
int x, y;
printf("Enter x: ");
scanf("%d",&x);
printf("Enter y: ");
scanf("%d",&y);

int sum = 0;
int smaller = ((x < y) ? x : y);
int bigger = ((x > y) ? x : y);

for(int i = smaller; i <= bigger; i++) {
    sum += i;
    printf("%d", i);
}
printf("\n%d", sum);
return 0;
}