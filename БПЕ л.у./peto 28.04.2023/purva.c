#include <stdio.h>
#define SIZE 50
int main() {
    
    int length = -1;
    int dumi = 1;
    char str[SIZE];
    char toSearch;
    int i, count;
    char character;


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

    for (toSearch = 'a'; toSearch <= 'z'; ++toSearch) {
        count = 0;
        i = 0;
        
        while(str[i] != '\0')
        {
            if(str[i] == toSearch)
            {
                count++;
            }
            i++;
        }

        printf("'%c' = %d\n", toSearch, count);
    }

    char str1[SIZE];
    char str2[SIZE];
    int length1, length2;
    printf("Enter first string: ");
    fgets(str1, SIZE, stdin);
    printf("%s", str1);
    printf("Enter second string: ");
    fgets(str2, SIZE, stdin);
    printf("%s", str2);



    for (int i = 0; str1[i] != '\0'; i++) {
        length1++;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        length2++;
    }

    for (int i = 0; i < length1 && i < length2; i++) {
    while(str1[i]!='\0' && str2[i]!='\0')  {
        if(str1[i] != str2[i]) {
            printf("Not the same");
            break;
            }
        }
    printf("They are the same");
    }
    return 0;
}

