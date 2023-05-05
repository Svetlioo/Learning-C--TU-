#include <stdio.h>
#include <string.h>

int main() {
    int guests = 0;
    int chairs = 0;
    int tables = 0;
    int cups_sets = 0;
    int dishes_sets = 0;
    float chair_price = 13.99;
    float table_price = 42.00;
    float cups_price = 5.98;
    float dishes_price = 21.02;

    char input[10];
    float total_cost = 0.0;

    printf("Enter the number of guests:\n");
    scanf("%d", &guests);

    while (strcmp(input, "PARTY!") != 0) {
        printf("Enter item (Table, Chair, Cups, Dishes) or PARTY! to end:\n");
        scanf("%s", input);

        if (strcmp(input, "Table") == 0) {
            tables++;
            total_cost += table_price;
        }
        else if (strcmp(input, "Chair") == 0) {
            chairs++;
            total_cost += chair_price;
        }
        else if (strcmp(input, "Cups") == 0) {
            cups_sets++;
            total_cost += cups_price;
        }
        else if (strcmp(input, "Dishes") == 0) {
            dishes_sets++;
            total_cost += dishes_price;
        }
    }

    tables = (guests + 7) / 8; 
    chairs = guests - tables * 8;
    dishes_sets = (guests + 5) / 6 - dishes_sets; 
    cups_sets = (guests + 1) / 2 - cups_sets; 

    printf("%.2f\n", total_cost);
    printf("%d Table(s)\n", tables);
    printf("%d Chair(s)\n", chairs);
    printf("%d Dishes Set(s)\n", dishes_sets);
    printf("%d Cup Set(s)\n", cups_sets);

    return 0;
}
