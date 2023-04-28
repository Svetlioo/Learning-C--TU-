#include <stdio.h>
#include <stdlib.h>
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
    int average = srednoaritm(masiv,n);
    int minimum = 5010;
    int mqsto;
    int minchislo;
    
    for (int i = 0; i < n; i++) {
        int blizko = abs(masiv[i] - average);
        if (blizko < minimum) {
            minimum = blizko;
            mqsto = i;
            minchislo = masiv[i];
        }
    }
        
    printf("Mqstoto e: %d\nNai-blizko do average e: %d\nAverage e: %d", mqsto, minchislo, average);
    return 0;
}