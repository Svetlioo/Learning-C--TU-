#include <stdio.h>
#define SIZE 50
int main() {
// Главни и малки букви
    char str[SIZE];
    char toSearchmalki, toSearchgolemi;
    int i, count;


    printf("Enter any string: ");
    fgets(str, SIZE, stdin);
    printf("%s", str);
     for (toSearchmalki = 'a'; toSearchmalki <= 'z'; ++toSearchmalki) {
        for( toSearchgolemi = 'Z'; toSearchgolemi <= 'Z'; ++toSearchgolemi) {
        count = 0;
        i = 0;
        while(str[i] != '\0')
        {
            if(str[i] == toSearchmalki)
            {
                str[i] = toSearchgolemi;
            }
            i++;
        }
     }
     }
    printf("%s", str);
    return 0;
}