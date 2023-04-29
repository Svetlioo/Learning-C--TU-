#include <stdio.h>
#define SIZE 50
int main() {
    char str1[SIZE], str2[SIZE];
    int i, flag = 0;

    printf("Въведи първия стринг: ");
    fgets(str1, SIZE, stdin);

    printf("Въведи втория стринг: ");
    fgets(str2, SIZE, stdin);

    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            flag = 1;
            break;
        }
    }

    if (flag == 0 && str1[i] == '\0' && str2[i] == '\0') {
        printf("Двата стринга са еднакви.\n");
    } else {
        printf("Двата стринга са различни.\n");
    }
    return 0;
}