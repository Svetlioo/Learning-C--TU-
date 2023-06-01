#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 35
#define regNomerSIZE 9


typedef struct  {
    char name[SIZE];
    char regNomer[regNomerSIZE];
    float price;
    int prioriret;
} TCar;

TCar inputCar() {
    TCar car;
    printf("Name: ");
    fgets(car.name, SIZE, stdin);
    fflush(stdin);
    car.name[strlen(car.name)-1] = '\0';
    printf("regNomer: ");
    fgets(car.regNomer, regNomerSIZE, stdin);
    fflush(stdin);
    printf("Price: ");
    scanf("%f", &car.price);
    fflush(stdin);
    printf("Prioritet: ");
    scanf("%d", &car.prioriret);
    fflush(stdin);
    return car;
}

void writeToFileandArray(TCar cars[]) {
    FILE *f;
    static int count = 0;

    if ((f=fopen("autoText.txt", "a")) == NULL) {
        perror("Opening file error: ");
        exit(1);
    }

    cars[count] = inputCar();
    int nameLength = strlen(cars[count].name);
    fprintf(f, "%d;%s;%s;%.2f;%d\n", nameLength, cars[count].name, cars[count].regNomer, cars[count].price, cars[count].prioriret);
    count++;
}
    

TCar cars[3];
int length = sizeof(cars)/sizeof(cars[0]); 


void nadSrednoAritm(TCar cars[]) {
    float srednoaritm;
    for (int i = 0; i < length; i++) {
        srednoaritm += cars[i].price;
    }
    srednoaritm /= length;
    printf("Sredno aritm: %.2f\n", srednoaritm);
    for (int i = 0; i < length; i++) {
        if (cars[i].price > srednoaritm) {
            printf("%s - %.2f\n", cars[i].regNomer, cars[i].price);
        }
    }
}


int main() {
    writeToFileandArray(cars);
    writeToFileandArray(cars);
    writeToFileandArray(cars);
    printf("Length: %d\n", length);
    nadSrednoAritm(cars); 
    return 0;
}






