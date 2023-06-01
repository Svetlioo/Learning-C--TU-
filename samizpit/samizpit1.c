#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 30
#define CH_SIZE 8



typedef struct {
    char name[SIZE];
    char chip[CH_SIZE];
    float price;
} TPet;



TPet inputPet(void) {
    TPet pet;
    FILE* f;
    if ((f = fopen("animalsText.txt", "a")) == NULL) {
        perror("Opening file error: ");
        exit(1);
    }
    printf("Name: ");
    fgets(pet.name, SIZE, stdin);
    fflush(stdin);
    pet.name[strlen(pet.name)-1] = '\0';
    printf("%s", pet.name);
    printf("Chip: ");
    fgets(pet.chip, CH_SIZE, stdin);
    fflush(stdin);
    printf("Price: ");
    scanf("%f", &pet.price);
    fflush(stdin);
    fprintf(f, "%s,%.2f\n", pet.name, pet.price);
    fclose(f);
    return pet;
}

void printNameByPrice(TPet pets[], unsigned size, float price) {
    bool isFound = false;
    for (int i = 0; i < size; i++) {
        if (pets[i].price == price) {
            isFound = true;
            printf("%s - %s\n", pets[i].name, pets[i].chip);
        }
    }
    if (!isFound) {
            printf("Not a pet with that price!");
        }
}

void readBinaryPrice(float price) {
    FILE* f;
    TPet pet;
    unsigned len;
    bool isFirst = true;
    if ((f=fopen("animalsBin.bin", "rb")) == NULL) {
        perror("Error opening binary file: ");
        exit(1);
    }
    while(true){   
        if (fread(&len, sizeof(unsigned), 1, f) != 1) {
            if (!feof(f)) {
                perror("Reading bin error: ");
                exit(1);
            }
            else {
                break;
            }
        }
        if (fread(pet.name, sizeof(char), len, f) != len) {
            perror("Reading bin error: ");
            exit(1);
            }
        pet.name[len] = '\0';
        if (fread(pet.chip, sizeof(char), CH_SIZE-1, f) != CH_SIZE-1) {
            perror("Reading bin error: ");
            exit(1);
            }
        pet.chip[CH_SIZE-1] = '\0';
        if (fread(&pet.price, sizeof(float), 1, f) != 1) {
            perror("Reading bin error: ");
            exit(1);
            }
        if (pet.price >= price) {
            if (!isFirst) {
                printf("---------\n");
            }
            else {
                isFirst = false;
            }
            printf("Bin OwnerName: %s\n", pet.name);
            printf("Bin Chip: %s\n", pet.chip);
            printf("Bin price: %.2f\n", pet.price);
        }
    }
    fclose(f);
}



void writeToBinary(TPet pets[], unsigned len) {
    FILE* f;
    unsigned size;
    if ((f=fopen("animalsBin.bin", "wb")) == NULL) {
        perror("Error opening binary file: ");
        exit(1);
    }
    
    for (int i = 0; i < len; i++ ) {
        size = strlen(pets[i].name);
        fwrite(&size, sizeof(unsigned), 1, f);
        fwrite(pets[i].name, sizeof(char), size, f);
        fwrite(pets[i].chip, sizeof(char), CH_SIZE-1, f);
        fwrite(&pets[i].price, sizeof(float), 1, f);
    }
    fclose(f);
}


int main() {
    unsigned pet_number = 3;
    TPet pets[pet_number];
    for (int i = 0; i < pet_number; i++) {
        pets[i] = inputPet();
    }
    printNameByPrice(pets, pet_number, 20);
    writeToBinary(pets,pet_number);
    readBinaryPrice(20);
    return 0;
}