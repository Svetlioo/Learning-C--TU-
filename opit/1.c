#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LEN 30
#define CH_LEN 8

typedef struct {
    char name[LEN];
    char chip[CH_LEN];
    float price;
} TPet;

TPet inputPet(void)
{
    TPet pet;
    FILE *f;

    printf("Name: ");
    fgets(pet.name,LEN,stdin);
    fflush(stdin);
    printf("Chip: ");
    pet.name[strlen(pet.name)-1]='\0';
    fgets(pet.chip,CH_LEN,stdin);
    fflush(stdin);
    printf("Price: ");
    scanf("%f",&pet.price);
    fflush(stdin);

    if((f=fopen("animalsText.txt","a"))==NULL) {
        perror("Open error: ");
        exit(2);
    }
    fprintf(f,"%s,%.2f\n",pet.name,pet.price);
    fclose(f);
    return pet;
}

int main() {
    inputPet();
    return 0;
}