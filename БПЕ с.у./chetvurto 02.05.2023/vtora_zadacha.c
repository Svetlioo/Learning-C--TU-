#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
   
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);

}

int main() {
    int size;
    int* ptr;
    printf("Enter size: ");
    scanf("%d", &size);
    ptr = (int*) malloc(size * sizeof(int));
    if(ptr  ==  NULL){
      printf("Memory not allocated. \n");
    }
     else {
        printf("Memory allocated succesfully. \n");
     }
    int newsize = size;
    int i = 0;
    int num;
    printf("Enter ptr[%d]: ", i);
    scanf("%d", &num);
    while(num!=0) {
        ptr[i] = num;
        i++;
    if (i > size) {
         ptr = (int *) realloc(ptr, size+1);
         newsize+=1;
    }
        printf("Enter ptr[%d]: ", i);
        scanf("%d", &num);
    }


    for(int i=0;i<newsize;i++){
      printf("%d\n", ptr[i]);
    }


    printf("\n\n\nSorted\n");
    bubbleSort(ptr, newsize);
    for(int i=0;i<newsize;i++){
      printf("%d\n", ptr[i]);
    }


    free(ptr);
    return 0;
}