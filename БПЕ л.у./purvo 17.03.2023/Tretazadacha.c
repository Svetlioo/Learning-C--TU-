#include <stdio.h>
int main(){
int x, y;
printf("Enter x: ");
scanf("%d",&x);
printf("Enter y: ");
scanf("%d",&y);

int sumchetni = 0;
int sumnechetni = 1;
int smaller = ((x < y) ? x : y);
int bigger = ((x > y) ? x : y);

for(int i = smaller; i <= bigger; i++) {
    if(i % 2 == 0){
    sumchetni += i;
    }
    else if (i % 2 != 0) {
        sumnechetni *= i;
    }
    printf("%d", i);
}
printf("\nSumata ot sbora na chetni: %d\nSumata ot proizvedenieto na nechetni: %d", sumchetni, sumnechetni);
return 0;
}