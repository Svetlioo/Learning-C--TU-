#include <stdio.h>
#include <stdlib.h>
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}


int main() {
int masiv[10];

for(int i = 0; i < 10; i++) {
    printf("Enter chislo: ");
    scanf("%d", &masiv[i]);
}

bubbleSort(masiv, 10);

for(int i = 0; i < 10; i++) {
    printf("%d\n", masiv[i]);
}

int sum = 0;
int sum2;
int start;
for(int i = 0; i < 10; i++) {
    if (masiv[i] == masiv[i+1]) {
        sum+=1;
    }
    else if (masiv[i] != masiv[i+1]) {
        if (sum2 < sum){
        sum2 = sum;
        start = i-sum2;
        }
        sum = 0;
    }
}
printf("len = %d\nstart = %d", sum2+1, start);

return 0;
}