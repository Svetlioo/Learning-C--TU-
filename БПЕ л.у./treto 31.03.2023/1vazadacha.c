#include <stdio.h>
int suma(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum+= arr[i];
    }
    return sum;
}
int main() {
    int n = 7;
    int masiv[n];
    for (int i = 0; i < n; i++) {
        printf("Enter number masiv[%d]: ", i);
        scanf("%d", &masiv[i]);
        while(masiv[i] > 5000 || masiv[i] < -5000){
             printf("Enter number masiv[%d]: ", i);
            scanf("%d", &masiv[i]);
        }
    }

    printf("Sumata e = %d\n", suma(masiv, n));

    return 0;
}