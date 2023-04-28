#include <stdio.h>
int main() {
 int n;
    printf("N = ");
    scanf("%d",&n);
    int k;
    printf("K = ");
    scanf("%d",&k);
     int arr[n];
    for (int i = 0; i < n; ++i) 
    {
        printf("Enter number:  ");
        scanf("%d",&arr[i]);
    }


    return 0;
}