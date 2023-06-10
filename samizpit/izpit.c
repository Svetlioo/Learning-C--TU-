#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define prihodrazhodSIZE 7
#define dateSIZE 11
#define nameSIZE 31

typedef struct {
    char prihodilirazhod[prihodrazhodSIZE];
    char date[dateSIZE];
    char poluchatel[nameSIZE];
    float suma;
} Transaction;


void readfromBinary(Transaction* transactions[]) {
    Transaction tranzakcii;
    FILE *f;
    int n;
    if ((f = fopen("statements.bin", "rb")) == NULL) {
        perror("Error opening bin file: ");
        exit(1);
    }

    
    if ((fread(&n,sizeof(int),1,f)) != 1) {
        if (!feof(f)) {
            perror("Error reading: ");
            exit(1);
        }
    }
    Transaction* transactions = (Transaction*)malloc(n * sizeof(Transaction));
    if (transactions == NULL) {
        perror("Memory allocation failed: ");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
    if ((fread(tranzakcii.prihodilirazhod,sizeof(char), prihodrazhodSIZE-1, f)) != prihodrazhodSIZE-1) {
        perror("Error reading: ");
        exit(1);
    }
    tranzakcii.prihodilirazhod[prihodrazhodSIZE-1] = '\0';
    *transactions[i] = tranzakcii;
    }
    fclose(f);
}

void highestSum(Transaction transactions[], unsigned len) {
    float naiGolqmaSuma = 0;
    int indexNaiGolqma;
    for (int i = 0; i < len; i++) {
        if (transactions[i].suma > naiGolqmaSuma) {
            naiGolqmaSuma = transactions[i].suma;
            indexNaiGolqma = i;
        }
    }
    printf("%s", transactions[indexNaiGolqma].prihodilirazhod);
    printf("%.2f",  transactions[indexNaiGolqma].suma);
}


void readToTextFile(Transaction transactions[], unsigned len, char data[]) {
    FILE* f;
    if ((f = fopen("balance.txt", "a")) == NULL) {
        perror("Error opening txt file: ");
        exit(1);
    }

    for (int i = 0; i < len; i++) {
        if (transactions[i].date == data) {
            fprintf(f,"%s", transactions[i].prihodilirazhod);
            fprintf(f,"%s", transactions[i].poluchatel);
            fprintf(f,"%s", transactions[i].date);
            fprintf(f,"%.2f", transactions[i].suma);
        }
    }
    fclose(f);
}


int main() {
    Transaction* transactions;
    free(transactions);
    return 0;
}