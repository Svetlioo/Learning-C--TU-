#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 31

typedef struct {
    int code;
    char artist[MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
    double price;
} Picture;

Picture* createPictureArray(int n)
{
    if (n <= 3 || n >= 30)
    {
        printf("Невалиден брой на елементите!\n");
        return NULL;
    }

    Picture* pictures = (Picture*)calloc(n, sizeof(Picture));
    if (pictures == NULL)
    {
        printf("Грешка при заделяне на памет!\n");
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Въведете информация за картина %d:\n", i + 1);
        printf("Уникален код: ");
        scanf("%d", &pictures[i].code);

        printf("Име на художника: ");
        scanf("%s", pictures[i].artist);

        printf("Название на картината: ");
        scanf("%s", pictures[i].name);

        printf("Цена: ");
        scanf("%lf", &pictures[i].price);
    }
    return pictures;
}

double calculateAveragePrice(Picture* pictures, int n, double min_price)
 {
    double sum = 0.0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (pictures[i].price > min_price) {
            sum += pictures[i].price;
            count++;
        }
    }

    if (count == 0) {
        return 0.0;
    }

    return sum / count;
}

int writePicturesToFile(Picture* pictures, int n, char letter) {
    FILE * file = fopen("info.txt", "w");
    if (file == NULL) {
        printf("Грешка при отваряне на файла!\n");
        return 0;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (pictures[i].artist[0] == letter) {
            fprintf(file, "%d; %s; %.2lfleva\n", pictures[i].code, pictures[i].name, pictures[i].price);
            count++;
        }
    }

    fclose(file);
    return count;
}

void readfromBinary(char artists[])
{
    Picture pictures;
    unsigned lenIme, lenZaglavie;
    FILE * f = fopen("picture.bin", "rb");
    if (f == NULL)
    {
        perror("Error opening file!");
        exit(1);
    }
    while(true)
    {
        if(fread(&pictures.code,sizeof(int),1,f) != 1)
           {
                if(!feof(f))
                {
                    perror("Error reading binary file!");
                    exit(1);
                }
                else
                {
                    break;
                }
           }
        if(fread(&lenIme,sizeof(unsigned),1, f) != 1)
           {
            perror("Error reading binary file!");
                    exit(1);
           }
        if(fread(pictures.artist,sizeof(char),lenIme,f) != lenIme)
        {
            perror("Error reading binary file!");
                    exit(1);
           }
        pictures.artist[lenIme] = '\0';

        if(fread(&lenZaglavie,sizeof(unsigned),1,f) != 1)
        {
            perror("Error reading binary file!");
                    exit(1);
           }

        if(fread(pictures.name,sizeof(char),lenZaglavie,f) != lenZaglavie)
        {
            perror("Error reading binary file!");
                    exit(1);
           }
        
        pictures.name[lenZaglavie] = '\0';

        if(fread(&pictures.price,sizeof(double),1,f) != 1)
        {
            perror("Error reading binary file!");
                    exit(1);
           }

        if (pictures.artist == artists) {
            printf("Picture title: %s\n", pictures.name);
            printf("Price: %.2f", pictures.price);
        }
    }
    fclose(f);
}

int main()
{
    int n;
    printf("Въведете брой елементи на масива: ");
    scanf("%d", &n);

    Picture* pictures = createPictureArray(n);
    if (pictures == NULL)
    {
        return 1;
    }
}
