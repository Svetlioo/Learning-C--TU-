#include <stdio.h>

int main() {
    float x,y,z;
    printf("Kvadratni metri: ");
    scanf("%f", &x);
    printf("Kilograma grozde: ");
    scanf("%f", &y);
    printf("Jelano kolichestvo za prodan: ");
    scanf("%f", &z);
    int rabotniciLoze;
    printf("Rabotnici: ");
    scanf("%d", &rabotniciLoze);
    float cqlo = 0.4 * x * y;
    float proizvedenoVino = cqlo / 2.5;
    float ostatuk = proizvedenoVino - z;

    if (ostatuk >= 0) {
        printf("Proizvedeno vino: %.2f litri\n", proizvedenoVino);
        printf("Vino za prodan: %.2f litri\n", z);
        printf("Ostatuk: %.2f litri\n", ostatuk);
        printf("Vseki rabotnik vzima: %.2f litri\n", ostatuk / rabotniciLoze);
    } else {
        printf("Proizvedeno vino: %.2f litri\n", proizvedenoVino);
        printf("Vino za prodan: %.2f litri\n", proizvedenoVino);
        printf("Need to produce %.2f more litri of wine\n", - ostatuk);
    }

    return 0;
}
