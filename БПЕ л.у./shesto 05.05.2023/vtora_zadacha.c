#include <stdio.h>
#include <string.h>

typedef struct Car {
    char brand[50];
    char model[50];
    int year;
    int price;
} car;

typedef struct Vehicles {
    struct Car car1,car2,car3;
    char brand[50];
    char model[50];
    int year;
    int price;
} vehicle;

int main() {
    vehicle airplane = {"Mercedes", "E-Class Executive Jet", 2015, 400000};
    vehicle car = {"Mercedes", "S-Class Sedan", 2021, 112000};
    vehicle motorcycle = {"Mercedes", "AMG F1 Safety Car", 2015, 120000};

    airplane.price = 400000;
    car.price = 112000;
    motorcycle.price = 120000;
    char vehicle1Compare[20], vehicle2Compare[20];
    printf("Enter vehicle1 to compare price: ");
    scanf("%s", vehicle1Compare);
    printf("Enter vehicle2 to compare price: ");
    scanf("%s", vehicle2Compare);

    if (strcmp(vehicle1Compare, "car") == 0 && strcmp(vehicle2Compare, "airplane") == 0) {
        printf("Price of car: %d, Price of airplane: %d", car.price, airplane.price);
        if (car.price != airplane.price) {
            printf("\nNot the same");
        } else {
            printf("\nThe same");
        }
    } 

     if (strcmp(vehicle1Compare, "car") == 0 && strcmp(vehicle2Compare, "motorcycle") == 0) {
        printf("Price of car: %d, Price of motorcycle: %d", car.price, motorcycle.price);
        if (car.price != motorcycle.price) {
            printf("\nNot the same");
        } else {
            printf("\nThe same");
        }
    } 


     if (strcmp(vehicle1Compare, "airplane") == 0 && strcmp(vehicle2Compare, "motorcycle") == 0) {
        printf("Price of airplane: %d, Price of motorcycle: %d", airplane.price, motorcycle.price);
        if (airplane.price != motorcycle.price) {
            printf("\nNot the same");
        } else {
            printf("\nThe same");
        }
    } 

    return 0;
}
