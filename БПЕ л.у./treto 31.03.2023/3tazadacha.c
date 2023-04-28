#include <stdio.h>

int srednoaritm(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum+= arr[i];
    }
    return sum/n;
}
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
    }
    printf("Sredno aritm: %d", srednoaritm(masiv,n));
    return 0;
}