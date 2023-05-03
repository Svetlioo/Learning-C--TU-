#include <stdio.h>
#define SIZE 50

int susedni(int arr[][SIZE], int red, int kolona, int N, int M) {
    int sum = 0;
    for (int i = red-1; i <= red+1; i++) {
        for (int j = kolona-1; j <= kolona+1; j++) {
            if (i >= 0 && i < N && j >= 0 && j < M && (i != red || j != kolona)) {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}


int main() {
    int N,M;
    printf("Enter N: ");
    scanf("%d",&N);
    printf("Enter M: ");
    scanf("%d",&M);
    int arr[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("Enter arrr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
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

    int max_sum = 0;
    int max_elem = arr[0][0];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int s = susedni(arr, i, j, N, M);
            if (s > max_sum) {
                max_sum = s;
                max_elem = arr[i][j];
            }
        }
    }

    printf("Chisloto s nai-golqm sbor ot susedni: %d\n", max_elem);

    return 0;
}





    
