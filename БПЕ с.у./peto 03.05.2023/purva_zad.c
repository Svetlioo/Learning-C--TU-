#include <stdio.h>

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
    printf("\n\n\n");
    int flag;
    int predishno = -1000;
    int sledvashto = 1000;
    for (int i = 0; i < N; i++) {
        flag = 0;
        predishno = -1000;
        printf("Red: ");
        for (int j = 0; j < M; j++) {
            printf("%d ",arr[i][j]);
            if(predishno < arr[i][j]) {
                predishno = arr[i][j];
            }
            else if(predishno > arr[i][j]) {
                flag = 1;
            }
        }
        flag == 0 ? printf(" : Narastvasht red") : printf(" : Nenarastvasht red");
        printf("\n");
    }

    for (int i = 0; i < M; i++) {
        flag = 0;
        sledvashto = 1000;
        printf("Kolona: \n");
        for (int j = 0; j < N; j++) {
            printf("%d \n",arr[j][i]);
            if(sledvashto > arr[j][i]) {
                sledvashto = arr[j][i];
            }
            else if(sledvashto <= arr[j][i]) {
                flag = 1;
            }
        }
        flag == 0 ? printf("Namalqvashta kolona") : printf("Nenamalqvashta kolona");
        printf("\n\n");
}

    return 0;   
}