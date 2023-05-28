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


void printPetsByPrice(TPet pets[],unsigned len,float price)
{
    bool isFound=false;

    for(int i=0;i<len;++i){
        if(pets[i].price==price){
            isFound=true;
            printf("%s - %s\n",pets[i].name,pets[i].chip);
        }
    }
    if(!isFound){
        puts("No such data...\n");
    }
}



int main() {
    TPet pets[LEN];
    const unsigned SIZE=2;

    for(int i=0;i<SIZE;++i){
        pets[i] = inputPet();
    }
    printPetsByPrice(pets,SIZE,22.22);
    return 0;
}



