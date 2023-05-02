#include <stdio.h>
#include <stdlib.h>

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
    
    int sum = 0;
    int min = 1000;
    int max = -1000;
    int chetni;
    for(int i=0;i<size;i++){
        printf("Enter ptr[%d]: ", i);
        scanf("%d", &ptr[i]);
        sum+= ptr[i];
        if (ptr[i] % 2 == 0) {
            chetni += ptr[i];
        }
        if (ptr[i] < min) {
            min = ptr[i];
        }
        if (ptr[i] > max) {
            max = ptr[i];
        }
    }


    for(int i=0;i<size;i++){
      printf("%d\n", ptr[i]);
    }
    printf("Sum is %d\n", sum);
    printf("Max is %d\n", max);
    printf("Min is %d\n", min);
    printf("Chetnite sa %d\n", chetni);
    free(ptr);
    return 0;
}