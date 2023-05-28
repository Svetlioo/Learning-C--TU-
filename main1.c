#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLIENT_NAME_LEN 30
#define CHIP_NAME_LEN 8

typedef struct Animal{
    char client_name[CLIENT_NAME_LEN];
    char chip_name[CHIP_NAME_LEN];
    float price;
} Animal_t;

FILE* file = NULL;

Animal_t create_animal(){
    Animal_t animal;
    size_t currnet_len;
    memset(animal.client_name, '\0', CLIENT_NAME_LEN);
    memset(animal.chip_name,'\0', CHIP_NAME_LEN);
    animal.price = 0;

    printf("name: ");
    fgets(animal.client_name,CLIENT_NAME_LEN, stdin);
    fflush(stdin);

    currnet_len = strlen(animal.client_name);
    animal.client_name[currnet_len - 1] = '\0';

    printf("chip: ");
    fgets(animal.chip_name,CHIP_NAME_LEN, stdin);
    fflush(stdin);

    printf("price: ");
    scanf("%f", &(animal.price));
    fflush(stdin);

    fprintf(file, "%s, %.2f\n", animal.client_name, animal.price);
    return animal;
}

/*
typedef struct Animal{
    char client_name[CLIENT_NAME_LEN];
    char chip_name[CHIP_NAME_LEN];
    float price;
} Animal_t;
*/
void print_animals_by_price(const Animal_t* const animals, const size_t size, const float price) {
    size_t i = 0;
    for (; i < size; ++i) {
        if (animals[i].price == price) {
            printf("%s - %s\n", animals[i].client_name, animals[i].chip_name);
        }
    }
}

void print_pets_from_bin_file(const float price) {
    unsigned name_len;

    Animal_t animal;
    memset(animal.client_name, '\0', CLIENT_NAME_LEN);
    memset(animal.chip_name,'\0', CHIP_NAME_LEN);
    animal.price = 0;

    FILE* f = fopen("animalsBin.bin", "rb");
    if (!f) {
        return;
    }

    while (!feof(f)) {
        fread(&name_len, sizeof name_len, 1, f);
        name_len = name_len > CLIENT_NAME_LEN ? CLIENT_NAME_LEN : name_len;

        fread(animal.client_name, sizeof(char), name_len, f);
        animal.client_name[name_len] = '\0';


        fread(animal.chip_name, sizeof(char), 7, f);
        animal.chip_name[CHIP_NAME_LEN] = '\0';


        fread(&animal.price, sizeof(float), 1, f);

        if (animal.price >= price) {
            printf("Bin OwnerName: %s\n", animal.client_name);
            printf("Bin Chip: %s\n", animal.chip_name);
            printf("Bin Price: %2.f\n", animal.price);
            printf("--------------\n");
        }
    }

    fclose(f);
}

int main()
{
    const size_t animal_size = sizeof(Animal_t);
    size_t animals_count = 2;
    Animal_t* animals_arr = (Animal_t*)calloc(animals_count, animal_size);
    file = fopen("animalsText.txt", "w");
    if (!file){
        return -1;
    }

    /*
    for (int i = 0; i < 3; ++i) {
        if (animals_count <= i) {
            printf("Reallocating memory for animals arr.\n");
            animals_count *= 2;
            printf("New animal count: %d\n", animals_count);
            animals_arr = realloc(animals_arr, animals_count * animal_size);
        }

        animals_arr[i] = create_animal();
    }

    print_animals_by_price(animals_arr, animals_count, 5.0);
    */

    print_pets_from_bin_file(5);


    fclose(file);
    free(animals_arr);
    return 0;
}
