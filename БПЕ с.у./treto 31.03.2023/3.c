#include <stdio.h>


int main() {
int n;
printf("Enter n: ");
scanf("%d", &n);
int masiv[n];
for(int i = 0; i < n; i++) {
    printf("Enter chislo: ");
    scanf("%d", &masiv[i]);
}


printf("Masiv: ");
for(int i = 0; i < n; i++) {
    printf("%d\n", masiv[i]);
}


printf("Obraten masiv: ");
for(int i = n-1; i>1; i--) {
    printf("%d",masiv[i]);
}




    return 0;
}