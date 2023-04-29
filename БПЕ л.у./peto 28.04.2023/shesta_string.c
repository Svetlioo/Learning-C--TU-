#include <stdio.h>
#include <ctype.h>

#define SIZE 50
int main() {
    
    char str[SIZE];
    char toSearch;
    int i, count;
    char character;
    printf("Enter any string: ");
    fgets(str, SIZE, stdin);
    printf("%s", str);
     for (toSearch = 'a'; toSearch <= 'z'; ++toSearch) {
        i = 0;
        
        while(str[i] != '\0')
        {
            if(str[i] == toSearch)
            {
                str[i] = toupper(str[i]);
            }
            i++;
        }
    }
    printf("Новия стринг: %s", str);
    return 0;
}