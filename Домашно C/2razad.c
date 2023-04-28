#include <stdio.h>
#include <stdbool.h>


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
    // 2ва задача а)
    FILE *f;
    int counter, num;

    f = fopen("numbers.bin", "wb");

    if(f == NULL) {
        perror("greshka otvarqne: ");
        exit(5);
    }

    int i = 0;
    while (true){
        printf("Press 0 to quit. Enter integer %d: ", i+1);
        scanf("%d", &num);
        if(num == 0) {
            break;
        }
        fwrite(&num, sizeof(int), 1, f);
        i++;
        counter++;

    }
    fclose(f);


    // 2ра задача б)
    f = fopen("numbers.bin", "rb");
    int buffer[counter];
    fread(buffer,sizeof(buffer),1,f);
    int chetni,nechetni;
    for(int i = 0; i < counter; i++) {
        int chislo = buffer [i];
        if (chislo % 2 != 0) {
            nechetni++;
        }
        else if (chislo % 2 == 0) {
            chetni++;
        }
        printf("%d\n", buffer[i]);
    }
    printf("\n");
    printf("Четни: %d\nНечетни: %d\n\n", chetni,nechetni);
    // 2ра задача в)
    printf("\n");
    Bubblesort(buffer,counter);
    for(int i = 0; i < counter; i++) {
        printf("%d\n", buffer[i]);
    }
    FILE *tekstov;
    tekstov = fopen("file.txt","w");
    for(int i = 0; i < counter; i++) {
        fprintf(tekstov,"%d\n", buffer[i]);
    }
    fclose(f);
    fclose(tekstov);
    return 0;
}
