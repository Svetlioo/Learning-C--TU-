#include <stdio.h>
int main() {
    int n = 7;
    int masiv[n];
    int max = 0;
    for (int i = 0; i < n; i++) {
        printf("Enter number masiv[%d]: ", i);
        scanf("%d", &masiv[i]);
        while(masiv[i] > 5000 || masiv[i] < -5000){
             printf("Enter number masiv[%d]: ", i);
            scanf("%d", &masiv[i]);
        }
        if (masiv[i] > max) {
            max = masiv[i];
        }
    }
    printf("Max: %d", max);
    return 0;
}