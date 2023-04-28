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
    
    for (int i = 0; i < n; ++i) 
    {
        for (int j = i + 1; j < n; ++j) 
        {
            if (arr[i] < arr[j]) 
            {
                int a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
    
    printf("%d",arr[k-1]);

    return 0;
}