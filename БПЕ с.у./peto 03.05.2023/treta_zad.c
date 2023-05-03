#include <stdio.h>
#define SIZE 50

int main() {
    int N,M;
    int min = 1000;
    int max = -1000;
    printf("Enter N: ");
    scanf("%d",&N);
    printf("Enter M: ");
    scanf("%d",&M);
    int arr[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("Enter arrr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
            if (min > arr[i][j]) {
                min = arr[i][j];
            }
            else if (max < arr[i][j]) {
                max = arr[i][j];
            }
        }
    }
    printf("Array[%d][%d]\n", N, M);
    for(int i=0; i<N; i++) {
      for(int j=0;j<M;j++) {
         printf("%d ", arr[i][j]);
         if(j==N){
            printf("\n");
         }
         if (N == M) {
         if(j+1 == N) {
            printf("\n");
         }
         }
      }
   }


  
  int minRow = 0, maxRow = 0;
  int minElement = arr[0][0], maxElement = arr[0][0];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (arr[i][j] < minElement) {
        minElement = arr[i][j];
        minRow = i;
      }
      if (arr[i][j] > maxElement) {
        maxElement = arr[i][j];
        maxRow = i;
      }
    }
  }

  for (int j = 0; j < M; j++) {
    int temp = arr[minRow][j];
    arr[minRow][j] = arr[maxRow][j];
    arr[maxRow][j] = temp;
  }


  printf("Reverse Array[%d][%d]\n", N, M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}
