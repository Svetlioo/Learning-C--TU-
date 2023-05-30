#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define LEN 30
#define chip_Len 8


typedef struct {
    char name[LEN];
    char chip[chip_Len];
    float price;
} TPet;



void PrintPetsByPrice(TPet pets[],unsigned len, float price) {
    bool isFound = false;
    for(int i = 0; i < len; i++) {
        if(pets[i].price == price) {
            isFound = true;
            printf("%s - %s\n", pets[i].name, pets[i].chip);
        }

    }
    if (!isFound) {
        printf("Not matching price\n");
    }
}



TPet inputPet(void) {
    TPet pet;
    FILE* f;
    if ((f=fopen("animalsText.txt", "a")) == NULL) {
        perror("Opening file error: ");
        exit(1);
    }
    printf("Name: ");
    fgets(pet.name, LEN, stdin);
    fflush(stdin);
    printf("Chip: ");
    pet.name[strlen(pet.name)-1] = '\0';
    fgets(pet.chip, chip_Len, stdin);
    fflush(stdin);
    printf("Price: ");
    scanf("%f", &pet.price);
    fflush(stdin);
    fprintf(f,"%s,%.2f\n", pet.name, pet.price);
    fclose(f);
    return pet;
}



void readBinary(float price) {
    FILE *f;
    TPet pet;
    unsigned len;
    bool isFirst = true;
    if ((f=fopen("animals.bin", "rb")) == NULL) {
        perror("Opening bin error: ");
        exit(1);
    }
    while(true) {
        if (fread(&len, sizeof(unsigned), 1, f) != 1) {
            if(!feof(f)) {
                perror("Reading bin error: ");
                fclose(f);
                exit(1);
            }
            else {
                break;
            }
        }
        if (fread(&pet.name, sizeof(char), len, f) != len) {
            perror("Reading bin error: ");
            fclose(f);
            exit(1);
        }
        pet.name[len] = '\0';
          if(fread(&pet.chip,sizeof(char),chip_Len-1,f)!=chip_Len-1){
                perror("Reading bin error: ");
                fclose(f);
                exit(12);
        }
        pet.chip[chip_Len-1]='\0';
        if(fread(&pet.price,sizeof(float),1,f)!=1){
                perror("Reading bin error: ");
                fclose(f);
                exit(13);
        }
        if (pet.price >= price) {
            if(!isFirst) {
                printf("---------\n");
            } else {
                isFirst = false;
            }
            printf("Bin OwnerName: %s\n", pet.name);
            printf("Bin Chip: %s\n",pet.chip);
            printf("Bin Price: %.2f\n",pet.price);
        }
    }
}


void writeToBin(TPet pets[],unsigned len)
{
    FILE *f = fopen("animalsBin.bin","wb");
    unsigned size;

    if(f==NULL){
        perror("Write error: ");
        exit(3);
    }
    for(int i=0;i<len;++i){
        size = strlen(pets[i].name);
        fwrite(&size,sizeof(unsigned),1,f);
        fwrite(pets[i].name,sizeof(char),size,f);
        fwrite(pets[i].chip,sizeof(char),chip_Len-1,f);
        fwrite(&pets[i].price,sizeof(float),1,f);
    }
    fclose(f);
}



int main() {
    const unsigned size = 3;
    TPet pets[LEN];
    for(int i = 0; i < size; ++i) {
        pets[i] = inputPet();
    }
    PrintPetsByPrice(pets, size, 30);
    
    return 0;
}