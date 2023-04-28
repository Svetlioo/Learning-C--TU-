#include <stdio.h>
int srednoaritm(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum+= arr[i];
    }
    return sum/n;
}
int main() {
    int masiv[5] = {6,2,3,4,5};
    printf("%d", srednoaritm(masiv, 5));

    return 0;
}