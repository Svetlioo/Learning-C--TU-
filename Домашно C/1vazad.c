#include <stdio.h>



void Bubblesort(int a[], int array_size)
{
    int i, j, temp;
    for (i = 0; i < (array_size - 1); ++i)
    {
        for (j = 0; j < array_size - 1 - i; ++j )
        {
            if (a[j] > a[j+1])
            {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
}


int main() {
    // 1ва задача а)
    FILE *f;
    int N, num;
    printf("Enter the number of integers: ");
    scanf("%d", &N);

    f = fopen("numbers.bin", "wb");

    if(f == NULL) {
        perror("greshka pri otvarqne: ");
        exit(2);
    }

    fwrite(&N, sizeof(int), 1, f);

    for(int i = 0; i < N; i++) {
        printf("Enter integer %d: ", i+1);
        scanf("%d", &num);
        fwrite(&num, sizeof(int), 1, f);
    }
    fclose(f);


    // 1ва задача б)
    f = fopen("numbers.bin", "rb");
    int buffer[N+1];
    fread(buffer,sizeof(buffer),1,f);
    int chetni,nechetni;
    for(int i = 0; i < N; i++) {
        int chislo = buffer [i+1];
        if (chislo % 2 != 0) {
            nechetni++;
        }
        else if (chislo % 2 == 0) {
            chetni++;
        }
        printf("%d\n", buffer[i+1]);
    }
    printf("\n");
    printf("Четни: %d\nНечетни: %d\n\n", chetni,nechetni);
    // 1ва задача в)
    int masiv[N];
    
    for(int i = 1; i < N+1; i++) {
        masiv[i-1] = buffer[i];
        printf("%d\n", buffer[i]);
    }
    printf("\n");
    Bubblesort(masiv,N);
    for(int i = 0; i < N; i++) {
        printf("%d\n", masiv[i]);
    }
    FILE *tekstov;
    tekstov = fopen("file.txt","w");
    for(int i = 0; i < N; i++) {
        fprintf(tekstov,"%d\n", masiv[i]);
    }
    fclose(f);
    fclose(tekstov);
    return 0;
}
