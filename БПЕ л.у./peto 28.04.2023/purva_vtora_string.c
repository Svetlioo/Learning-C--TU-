#include <stdio.h>
#define SIZE 50
int main() {
    
    int length = -1;
    int dumi = 1;
    char str[SIZE];
    printf("Enter any string: ");
    fgets(str, SIZE, stdin);
    printf("%s", str);

       for (int i = 0; str[i] != '\0'; i++) {
        length++;
        if  (str[i] == ' ') {
            dumi++;
        }
    }
   

    printf("Дължина на стринг: %d\n", length);
    printf("Думи в стринга: %d\n", dumi);
    return 0;
}