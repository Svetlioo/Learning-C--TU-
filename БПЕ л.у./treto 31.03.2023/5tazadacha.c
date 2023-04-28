#include <stdio.h>
int main() {
    int n = 5;
    int masiv[n];
    int max = 0;
    for (int i = 0; i < n; i++) {
        printf("Enter number masiv[%d]: ", i);
        scanf("%d", &masiv[i]);
        while(masiv[i] > 25 || masiv[i] < 5){
             printf("Enter number masiv[%d]: ", i);
            scanf("%d", &masiv[i]);
        }
    }
    int sumchetni = 0;
    int chetnicount = 0;
    int sumnechetni = 0;
    int nechetnicount = 0;
for (int i = 0; i < n; i++) {
    if (masiv[i] % 2 == 0) {
        sumchetni+= masiv[i];
        chetnicount+=1;
    }
    else {
        sumnechetni+= masiv[i];
        nechetnicount+=1;
    }
}
    printf("Suma na chetni: %d \nSuma na nechetni: %d\nAvgchetni: %d\nAvgnechetni: %d\n", sumchetni,sumnechetni, sumchetni/chetnicount, sumnechetni/nechetnicount);
    return 0;
}