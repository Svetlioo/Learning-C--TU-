#include <stdio.h>
#include <stdlib.h>

#define MAX_ptr 100

int count = 0;

void add(int x, int* ptr) {
    if (count < MAX_ptr) {
        ptr[count] = x;
        count++;
    } else {
        ptr = (int *) realloc(ptr, MAX_ptr+1*(sizeof(int)));
        ptr[count] = x;
        count++;
    }
}


void delete(int x, int* ptr) {
    int i, j;
    for (i = 0, j = 0; i < count; i++) {
        if (ptr[i] != x) {
            ptr[j] = ptr[i];
            j++;
        }
    }
    count = j;
}


void smallest(int* ptr) {
    if (count == 0) {
        printf("Prazen array\n");
        return;
    }

    int i, min;
    min = ptr[0];
    for (i = 1; i < count; i++) {
        if (ptr[i] < min) {
            min = ptr[i];
        }
    }

    printf("Smallest element: %d\n", min);
}



int main() {
    int* ptr;
    ptr = (int*) malloc(MAX_ptr * sizeof(int));
    if(ptr  ==  NULL){
      printf("Memory not allocated. \n");
    }
     else {
        printf("Memory allocated succesfully. \n");
     }
    add(2,ptr);
    add(3,ptr);
    add(5,ptr);
    add(12,ptr);

    smallest(ptr); 

    delete(2,ptr);

    smallest(ptr); 

    free(ptr);
    return 0;
}
