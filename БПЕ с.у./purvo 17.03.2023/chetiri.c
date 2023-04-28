#include <stdio.h>
int main() {
    float celcius;
    printf("Enter Celcius: ");
    scanf("%f", &celcius);
    printf("%.2f C = %.2f Farenheit\n", celcius ,celcius * 1.8 + 32);

    float centimeters;
    printf("Enter cm: ");
    scanf("%f", &centimeters);
    printf("%.2f cm = %.2f inches", centimeters, centimeters / 2.54);
return 0;
}