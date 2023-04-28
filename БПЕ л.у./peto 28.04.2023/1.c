#include <stdio.h>

// int initialize(int masiv[][], int x, int y) {
// }

int main() {
    int x,y;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);


   int masiv[x][y];

   int i, j;
   for(i=0; i<x; i++) {
      for(j=0;j<y;j++) {
         printf("Enter value for masiv[%d][%d]:", i, j);
         scanf("%d", &masiv[i][j]);
      }
   }

  printf("Two Dimensional masivay elements:\n");
   for(i=0; i<x; i++) {
      for(j=0;j<y;j++) {
         printf("%d ", masiv[i][j]);
         if(j==x){
            printf("\n");
         }
         if (x == y) {
         if(j+1 == x) {
            printf("\n");
         }
         }
      }
   }
    
    int N = x;
      // извеждане на главния диагонал
    printf("Главен диагонал: ");
    for(i = 0; i < N; i++) {
        printf("%d ", masiv[i][i]);
    }
    printf("\n");
    
    // извеждане на второстепенния диагонал
    printf("Второстепенен диагонал: ");
    for(i = 0; i < N; i++) {
        printf("%d ", masiv[i][N - 1 - i]);
    }
    printf("\n");
    
    // извеждане на елементите над главния диагонал
    printf("Елементи над главния диагонал: ");
    for(i = 0; i < N; i++) {
        for(j = i + 1; j < N; j++) {
            printf("%d ", masiv[i][j]);
        }
    }
    printf("\n");
    
    // извеждане на елементите под главния диагонал
    printf("Елементи под главния диагонал: ");
    for(i = 0; i < N; i++) {
        for(j = 0; j < i; j++) {
            printf("%d ", masiv[i][j]);
        }
    }
    printf("\n");
    
    // магически квадрат 
    printf("Магически квадрат: \n");
    int sumrow, sumcolumn;
    for (int i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            sumrow += masiv[i][j];
            sumcolumn += masiv[j][i];
        }
    }
    printf("row: %d\ncolumn: %d\n", sumrow, sumcolumn);
    

    return 0;
}
   




