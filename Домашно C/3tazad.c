#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LENMARKA 10
#define LENMODEL 5


typedef struct {
    char marka[LENMARKA];
    char model[LENMODEL];
    float obem;
    float cena;
    char registraciq;
    
} Avtokushta;

Avtokushta input(void)
{
    Avtokushta car;
    FILE *binary;
    FILE  *text;
    printf("Enter marka: ");
    fgets(car.marka, LENMARKA, stdin);
    fflush(stdin);
    printf("Enter model: ");
    fgets(car.model, LENMODEL, stdin);
    fflush(stdin);
    printf("Enter obem: ");
    scanf("%f",&car.obem);
    fflush(stdin);
    printf("Enter cena: ");
    scanf("%f",&car.cena);
    fflush(stdin);
    printf("Enter registraciq Y/N: ");
    scanf("%c",&car.registraciq);
    fflush(stdin);
    binary = fopen("binary.bin", "wb");
    if (binary == NULL) {
        perror("Open error: ");
        exit(1);
    }
    fprintf(binary, "%s, %s, %f, %.2f, %c\n", car.marka, car.model, car.obem, car.cena, car.registraciq);
    
    text = fopen("file.txt", "w");
    if (text == NULL) {
        perror("Open error: ");
        exit(1);
    }
    fprintf(text, "%s%s%.2f\n%.2f\n%c\n", car.marka, car.model, car.obem, car.cena, car.registraciq);
    fwrite(&car, sizeof(Avtokushta), 1, binary);
    fclose(binary);
    fclose(text);
    binary = fopen("binary.bin", "rb");
    if (binary == NULL) {
        perror("Open error: ");
        exit(1);
    }
    while (fread(&car, sizeof(Avtokushta), 1, binary) == 1) {
        printf("%s, %s, %f, %.2f, %c\n", car.marka, car.model, car.obem, car.cena, car.registraciq);
    }
    fclose(binary);
    
    text = fopen("file.txt", "r");
    if (text == NULL) {
        perror("Open error: ");
        exit(1);
    }
    while (fscanf(text, "%s%s%f%f %c", car.marka, car.model, &car.obem, &car.cena, &car.registraciq) == 5) {
        printf("%s%s%.2f\n%.2f\n%c\n", car.marka, car.model, car.obem, car.cena, car.registraciq);
    }
    fclose(text);
    return car;
    
}

int main() {
    input();
    
    return 0;
}

