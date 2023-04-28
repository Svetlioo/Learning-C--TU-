#include <stdio.h>
int main() {
float cena_kartofi_lv;
printf("Enter cena na kartofi: ");
scanf("%f", &cena_kartofi_lv);
float cena_chereshi_lv;
printf("Enter cena na chereshi: ");
scanf("%f", &cena_chereshi_lv);
int obshti_kg_kartofi;
printf("Enter obsht kg kartofi: ");
scanf("%d", &obshti_kg_kartofi);
int obshti_kg_chereshi;
printf("Enter obsht kg chereshi: ");
scanf("%d", &obshti_kg_chereshi);

// prihodi v evro 1.96

float prihodi = ((cena_kartofi_lv * obshti_kg_kartofi) + (cena_chereshi_lv * obshti_kg_chereshi)) / 1.96;
printf("Prihodi: %.2f euro", prihodi);
return 0;
}